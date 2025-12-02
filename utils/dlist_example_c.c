/*===========================================================================*/
/**
 * @file dlist_example.c
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Example on how to use the Double Linked List module
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
#include "dlist.h"

/*===========================================================================*
 * The matching function
 *===========================================================================*/
bool match_int(const void *node_data, const void *criteria)
{
    return *(const int *)node_data == *(const int *)criteria;
}

/*===========================================================================*
 * The usage example
 *===========================================================================*/
int dlist_example (void)
{
    DList dl;
    dlist_init(&dl);
    int a = 10, b = 20, c = 30;

    printf("push head: %d\n", a);
    dlist_push_head(&dl, &a);

    printf("push tail: %d\n", b);
    dlist_push_tail(&dl, &b);

    printf("push tail: %d\n", c);
    dlist_push_tail(&dl, &c);

    int key = 20;
    printf("Contains 20? %s\n", dlist_contains(&dl, &key, match_int) ? "yes" : "no");

    int *p = dlist_pop_head(&dl);
    if (p)
        printf("pop head: %d\n", *p);

    p = dlist_pop_tail(&dl);
    if (p)
        printf("pop tail: %d\n", *p);

    return 0;
}
