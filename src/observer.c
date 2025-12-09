/*===========================================================================*/
/**
 * @file observer.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Implementation of a small Observer pattern framework for C.
 * This file contains the internal logic for managing observers in a Subject:
 * - Initializing a subject with a user-provided buffer
 * - Registering observer callbacks
 * - Unregistering callbacks (O(1) using swap-delete)
 * - Notifying all subscribed observers
 * The implementation avoids dynamic memory and relies solely on arrays
 * provided by the caller. This makes it appropriate for real-time or
 * embedded environments.
 *
 * ### How It Works
 * - A `Subject` holds an array of `Observer` items.
 * - Each `Observer` stores:
 *      - A callback function
 *      - A user argument passed back during notifications
 * - When `subject_notify()` is called, each callback is invoked in the order
 *   they are stored.
 * 
 * @warning The API does not check for duplicate registrations. If the same
 *          callback is registered more than once, it will be called multiple
 *          times.
 * 
 * @see observer.h for public API and example usage.
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
#include "observer.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/
// int working_arr[100];

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
 * Name         subject_init
 * Description  Initialize the observers for the subject
 *****************************************************************************/
void subject_init(Subject *s, Observer *buffer, size_t capacity) {
    s->observers = buffer;
    s->capacity = capacity;
    s->count = 0;
}

/*****************************************************************************
 * Name         subject_register
 * Description  Register an observer for the subject
 *****************************************************************************/
int subject_register(Subject *s, ObserverCallback cb, void *user_arg) {
    if (s->count >= s->capacity) return -1;

    s->observers[s->count].callback = cb;
    s->observers[s->count].user_arg = user_arg;
    s->count++;

    return 0;
}

/*****************************************************************************
 * Name         subject_unregister
 * Description  Unregister an observer for the subject
 *****************************************************************************/
int subject_unregister(Subject *s, ObserverCallback cb) {
    for (size_t i = 0; i < s->count; i++) {
        if (s->observers[i].callback == cb) {
            /* Replace removed with last element */
            s->observers[i] = s->observers[s->count - 1];
            s->count--;
            return 0;
        }
    }
    return -1;
}

/*****************************************************************************
 * Name         subject_notify
 * Description  Notify to all the observers about an event in the subject
 *****************************************************************************/
void subject_notify(Subject *s) {
    for (size_t i = 0; i < s->count; i++) {
        s->observers[i].callback(s, s->observers[i].user_arg);
    }
}
