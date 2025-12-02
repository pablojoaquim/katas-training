/*===========================================================================*/
/**
 * @file dlist.c
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Double Linked Lists implementation
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
#include "dlist.h"

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
 * Name         dlist_init
 * Description  Initialize the list structure, leaving it empty.
 *****************************************************************************/
void dlist_init(DList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

/*****************************************************************************
 * Name         dlist_push_head
 * Description  Insert a new element at the beginning of the list.
 *****************************************************************************/
void dlist_push_head(DList *list, void *data)
{
    DListNode *node = malloc(sizeof(DListNode));
    node->data = data;
    node->prev = NULL;
    node->next = list->head;

    if (list->head)
        list->head->prev = node;
    else
        list->tail = node;

    list->head = node;
}

/*****************************************************************************
 * Name         dlist_push_tail
 * Description  Insert a new element at the end of the list.
 *****************************************************************************/
void dlist_push_tail(DList *list, void *data)
{
    DListNode *node = malloc(sizeof(DListNode));
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;

    if (list->tail)
        list->tail->next = node;
    else
        list->head = node;

    list->tail = node;
}

/*****************************************************************************
 * Name         dlist_pop_head
 * Description  Remove and return the element at the beginning of the list.
 *              Returns NULL if the list is empty.
 *****************************************************************************/
void *dlist_pop_head(DList *list)
{
    if (!list->head)
        return NULL;

    DListNode *node = list->head;
    void *data = node->data;

    list->head = node->next;
    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(node);
    return data;
}

/*****************************************************************************
 * Name         dlist_pop_tail
 * Description  Remove and return the element at the end of the list.
 *              Returns NULL if the list is empty.
 *****************************************************************************/
void *dlist_pop_tail(DList *list)
{
    if (!list->tail)
        return NULL;

    DListNode *node = list->tail;
    void *data = node->data;

    list->tail = node->prev;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(node);
    return data;
}

/*****************************************************************************
 * Name         dlist_contains
 * Description  Check if the list contains an element matching the criteria
 *              using the provided comparison callback.
 *              Returns true if at least one match is found.
 *****************************************************************************/
bool dlist_contains(const DList *list, const void *criteria, dlist_match_fn match)
{
    DListNode *cur = list->head;
    while (cur)
    {
        if (match(cur->data, criteria))
            return true;
        cur = cur->next;
    }
    return false;
}
