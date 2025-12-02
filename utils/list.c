/*===========================================================================*/
/**
 * @file list.c
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Simple Linked Lists implementation
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
#include <stdlib.h>
#include "list.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

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
 * Name         list_init
 * Description  Initialize the list structure, leaving it empty.
 *****************************************************************************/
void list_init(List *list)
{
    list->head = NULL;
    list->tail = NULL;
}

/*****************************************************************************
 * Name         list_push_head
 * Description  Insert a new element at the beginning of the list.
 *****************************************************************************/
void list_push_head(List *list, void *data)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->data = data;
    node->next = list->head;

    list->head = node;
    if (list->tail == NULL)
        list->tail = node;
}

/*****************************************************************************
 * Name         list_push_tail
 * Description  Insert a new element at the end of the list.
 *****************************************************************************/
void list_push_tail(List *list, void *data)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;

    if (list->tail)
    {
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        list->head = node;
        list->tail = node;
    }
}

/*****************************************************************************
 * Name         list_pop_head
 * Description  Remove and return the element at the beginning of the list.
 *              Returns NULL if the list is empty.
 *****************************************************************************/
void *list_pop_head(List *list)
{
    if (!list->head)
        return NULL;

    ListNode *node = list->head;
    void *data = node->data;

    list->head = node->next;
    if (list->head == NULL)
        list->tail = NULL;

    free(node);
    return data;
}

/*****************************************************************************
 * Name         list_pop_tail
 * Description  Remove and return the element at the end of the list.
 *              Returns NULL if the list is empty.
 *****************************************************************************/
void *list_pop_tail(List *list)
{
    if (!list->tail)
        return NULL;

    ListNode *cur = list->head;
    ListNode *prev = NULL;

    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }

    void *data = cur->data;

    if (prev)
    {
        prev->next = NULL;
        list->tail = prev;
    }
    else
    {
        list->head = NULL;
        list->tail = NULL;
    }

    free(cur);
    return data;
}

/*****************************************************************************
 * Name         list_contains
 * Description  Check if the list contains an element matching the criteria
 *              using the provided comparison callback.
 *              Returns true if at least one match is found.
 *****************************************************************************/
bool list_contains(const List *list, const void *criteria, list_match_fn match)
{
    ListNode *cur = list->head;
    while (cur)
    {
        if (match(cur->data, criteria))
            return true;
        cur = cur->next;
    }
    return false;
}
