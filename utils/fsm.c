/*===========================================================================*/
/**
 * @file fsm.c
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Finite state machine in C (FSM)
 * - Support for entry/exit/do
 * - Support for guards, actions and transitions table
 * - Simple event queue added
 * - C99 style
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - @todo Update list of other applicable standards
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define FSM_EVENT_QUEUE_SIZE 32

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define STATE(id, name, entry, exit, dofn) \
{ id, name, entry, exit, dofn }

#define TRANS(src, evt, guard, action, dst) \
{ src, evt, guard, action, dst }

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef int fsm_state_id_t;
typedef int fsm_event_id_t;

typedef struct fsm_ctx fsm_ctx_t; /* forward */

/* Function prototypes for state/transitions */
typedef void (*state_fn_t)(fsm_ctx_t *ctx);
typedef bool (*guard_fn_t)(fsm_ctx_t *ctx, void *event_data);
typedef void (*action_fn_t)(fsm_ctx_t *ctx, void *event_data);

/* State management structure */
typedef struct fsm_state
{
    fsm_state_id_t id; /* id */
    const char *name;  /* name (mainly for debug) */

    state_fn_t on_entry; /* on entry */
    state_fn_t on_exit;  /* on exit */
    state_fn_t on_do;    /* do it while keep in the state */
} fsm_state_t;

/* Transition management structure */
typedef struct fsm_transition
{
    fsm_state_id_t src; /* source state */
    fsm_event_id_t evt; /* event trigger */
    guard_fn_t guard;   /* guard (NULL if NA) */
    action_fn_t action; /* action to execute during transition (NULL if NA) */
    fsm_state_id_t dst; /* destination state (same as src for loops) */
} fsm_transition_t;

/* Event queue (simple) - adaptable */
typedef struct fsm_event
{
    fsm_event_id_t id;
    void *data; /* data pointer (optional) */
} fsm_event_t;

typedef struct fsm_event_queue
{
    fsm_event_t buf[FSM_EVENT_QUEUE_SIZE];
    int head;
    int tail;
    int count;
} fsm_event_queue_t;

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/
/* FSM context */
struct fsm_ctx
{
    const fsm_state_t *current;
    const fsm_state_t *states; /* states array */
    size_t state_count;

    const fsm_transition_t *transitions; /* transitions array */
    size_t transition_count;

    fsm_event_queue_t evq; /* ev queue */

    /* user data if necessary */
    void *user_data;
};

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*****************************************************************************
 * Event queue management functions
 *****************************************************************************/
static void eq_init(fsm_event_queue_t *q)
{
    q->head = q->tail = q->count = 0;
}

static bool eq_is_empty(fsm_event_queue_t *q)
{
    return (0 == q->count);
}

static bool eq_is_full(fsm_event_queue_t *q)
{
    return (FSM_EVENT_QUEUE_SIZE == q->count);
}

static bool eq_push(fsm_event_queue_t *q, fsm_event_t ev)
{
    if (eq_is_full(q))
        return false;
    q->buf[q->tail] = ev;
    q->tail = (q->tail + 1) % FSM_EVENT_QUEUE_SIZE;
    q->count++;
    return true;
}

static bool eq_pop(fsm_event_queue_t *q, fsm_event_t *out)
{
    if (eq_is_empty(q))
        return false;
    *out = q->buf[q->head];
    q->head = (q->head + 1) % FSM_EVENT_QUEUE_SIZE;
    q->count--;
    return true;
}

/*****************************************************************************
 * Helper functions
 *****************************************************************************/
static const fsm_state_t *fsm_find_state(const fsm_ctx_t *ctx, fsm_state_id_t id)
{
    for (size_t i = 0; i < ctx->state_count; ++i)
    {
        if (ctx->states[i].id == id)
            return &ctx->states[i];
    }
    return NULL;
}

static const fsm_transition_t *fsm_find_transition(const fsm_ctx_t *ctx, fsm_state_id_t src, fsm_event_id_t evt)
{
    for (size_t i = 0; i < ctx->transition_count; ++i)
    {
        const fsm_transition_t *t = &ctx->transitions[i];
        if (t->src == src && t->evt == evt)
            return t;
    }
    return NULL;
}

/*****************************************************************************
 * Name         fsm_change_state
 * Description  Move to the destination state, executing on_exit from current 
 *              state and on_entry in the destination state.
 *****************************************************************************/
static void fsm_change_state(fsm_ctx_t *ctx, const fsm_state_t *dst)
{
    if (ctx->current == dst)
        return;

    if (ctx->current && ctx->current->on_exit)
        ctx->current->on_exit(ctx);

    ctx->current = dst;

    if (ctx->current && ctx->current->on_entry)
        ctx->current->on_entry(ctx);
}

/*****************************************************************************
 * Name         fsm_init
 * Description  Move the current state to the initial state and executes its
 *              on_entry function if any.
 *****************************************************************************/
static void fsm_init(fsm_ctx_t *ctx, fsm_state_id_t initial_id)
{
    eq_init(&ctx->evq);
    ctx->current = fsm_find_state(ctx, initial_id);
    if (ctx->current && ctx->current->on_entry)
        ctx->current->on_entry(ctx);
}

/*****************************************************************************
 * Name         fsm_handle_event
 * Description  If the current state have a transition related to the received
 *              event, the guard is checked, the action related is taken, and
 *              then moved to the destination state
 *****************************************************************************/
static void fsm_handle_event(fsm_ctx_t *ctx, fsm_event_t ev)
{
    if (!ctx->current)
        return;

    const fsm_transition_t *t = fsm_find_transition(ctx, ctx->current->id, ev.id);
    if (!t)
        return;

    if (t->guard && !t->guard(ctx, ev.data))
        return;

    if (t->action)
        t->action(ctx, ev.data);

    const fsm_state_t *dst = fsm_find_state(ctx, t->dst);
    if (dst)
        fsm_change_state(ctx, dst);
}

/*****************************************************************************
 * Name         fsm_process_events
 * Description  Process the received events (till 'max' events)
 *****************************************************************************/
static void fsm_process_events(fsm_ctx_t *ctx, int max)
{
    fsm_event_t ev;
    int count = 0;

    while (count < max && eq_pop(&ctx->evq, &ev))
    {
        fsm_handle_event(ctx, ev);
        count++;
    }
}

/*****************************************************************************
 * Name         fsm_post_event
 * Description  Execute the on_do() of the current state (if any)
 *****************************************************************************/
static bool fsm_post_event(fsm_ctx_t *ctx, fsm_event_id_t id, void *data)
{
    fsm_event_t ev = {.id = id, .data = data};
    return eq_push(&ctx->evq, ev);
}

/*****************************************************************************
 * Name         fsm_run_do_action
 * Description  Execute the on_do() of the current state (if any)
 *****************************************************************************/
static void fsm_run_do_action(fsm_ctx_t *ctx)
{
    if (ctx->current && ctx->current->on_do)
        ctx->current->on_do(ctx);
}


/*****************************************************************************
 * EXAMPLE
 *****************************************************************************/
enum { S_IDLE = 1, S_WORKING = 2, S_ERROR = 3 };
enum { EV_START = 1, EV_STOP = 2, EV_FAIL = 3, EV_RESET = 4 };

static void idle_entry(fsm_ctx_t *ctx) { printf("ENTER IDLE\n"); }
static void idle_exit (fsm_ctx_t *ctx) { printf("EXIT IDLE\n"); }
static void idle_do (fsm_ctx_t *ctx) { printf("IDLE...\n"); }

static void work_entry(fsm_ctx_t *ctx) { printf("ENTER WORKING\n"); }
static void work_exit (fsm_ctx_t *ctx) { printf("EXIT WORKING\n"); }
static void work_do (fsm_ctx_t *ctx) { printf("WORKING...\n"); }

static void err_entry (fsm_ctx_t *ctx) { printf("ENTER ERROR\n"); }
static void err_exit (fsm_ctx_t *ctx) { printf("EXIT ERROR\n"); }
static void err_do (fsm_ctx_t *ctx) {}

static bool guard_always(fsm_ctx_t *ctx, void *d) 
{ 
    return true; 
}
static bool guard_if_positive(fsm_ctx_t *ctx, void *d) 
{
    if (!d) 
        return false;
    return ((*(int*)d) > 0);
}

static void action_start(fsm_ctx_t *ctx, void *d) { printf("ACTION: start\n"); }
static void action_stop (fsm_ctx_t *ctx, void *d) { printf("ACTION: stop\n"); }
static void action_fail (fsm_ctx_t *ctx, void *d) { printf("ACTION: fail reported\n"); }


static fsm_state_t states[] = 
{
    STATE(S_IDLE, "IDLE", idle_entry, idle_exit, idle_do),
    STATE(S_WORKING, "WORKING", work_entry, work_exit, work_do),
    STATE(S_ERROR, "ERROR", err_entry, err_exit, err_do)
};

static fsm_transition_t transitions[] = {
    TRANS(S_IDLE, EV_START, guard_always, action_start, S_WORKING),
    TRANS(S_WORKING, EV_STOP, guard_always, action_stop, S_IDLE),
    TRANS(S_WORKING, EV_FAIL, guard_if_positive, action_fail, S_ERROR),
    TRANS(S_ERROR, EV_RESET, guard_always, NULL, S_IDLE),
};

void fsm_example(void)
{
    fsm_ctx_t ctx;
    memset(&ctx, 0, sizeof(ctx));

    ctx.states = states;
    ctx.state_count = sizeof(states)/sizeof(states[0]);
    ctx.transitions = transitions;
    ctx.transition_count = sizeof(transitions)/sizeof(transitions[0]);

    fsm_init(&ctx, S_IDLE);

    /* Post some events */
    fsm_post_event(&ctx, EV_START, NULL);
    fsm_post_event(&ctx, EV_FAIL, NULL); /* guard_if_positive -> require positive data, so no transitioning expected */

    int positive = 5;
    fsm_post_event(&ctx, EV_FAIL, &positive);

    fsm_post_event(&ctx, EV_RESET, NULL);

    /* Process up to 10 events */
    fsm_process_events(&ctx, 10);

    /* Execute the on_do() of the current state */
    for (int i = 0; i < 3; ++i) {
        fsm_run_do_action(&ctx);
    }
}