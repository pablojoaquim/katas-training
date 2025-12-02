#ifndef DLIST_H
#define DLIST_H

/*===========================================================================*/
/**
 * @file dlist.h
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * API for the Double Linked Lists implementation
 *
 * @todo Add full description here
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
 * Header Files (Common to C and C++)
 *===========================================================================*/
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
/*===========================================================================*
 * Header Files (C++ only)
 *===========================================================================*/
#endif

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
typedef struct DListNode
{
    void *data;
    struct DListNode *next;
    struct DListNode *prev;
} DListNode;

typedef struct
{
    DListNode *head;
    DListNode *tail;
} DList;

/*****************************************************************************
 * @typedef    dlist_match_fn
 * @brief      Callback used by list_contains() to compare node data against
 *             a user-provided criteria.
 * @param[in]  node_data   Pointer to the data stored in the list node.
 * @param[in]  criteria    Pointer to the matching criteria.
 * @return     true if node_data matches criteria, false otherwise.
 ******************************************************************************/
typedef bool (*dlist_match_fn)(const void *node_data, const void *criteria);

/*===========================================================================*
 * Exported Classes (C++ only)
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add C++ class declarations here.
#endif

/*===========================================================================*
 * Exported C Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
// @todo: Add pure C function prototypes here.
/*****************************************************************************
 * @fn         dlist_init
 * @brief      Initializes a list structure, setting it to an empty state.
 * @param [in] list   Pointer to the list instance to initialize.
 * @return     None
 ******************************************************************************/
void dlist_init(DList *list);

/*****************************************************************************
 * @fn         dlist_push_head
 * @brief      Inserts a new element at the beginning of the list.
 * @param[in]  list   Pointer to the list instance.
 * @param[in]  data   Pointer to the data to be stored in the new node.
 * @return     None.
 ******************************************************************************/
void dlist_push_head(DList *list, void *data);

/*****************************************************************************
 * @fn         dlist_push_tail
 * @brief      Inserts a new element at the end of the list.
 * @param[in]  list   Pointer to the list instance.
 * @param[in]  data   Pointer to the data to be stored in the new node.
 * @return     None.
 ******************************************************************************/
void dlist_push_tail(DList *list, void *data);

/*****************************************************************************
 * @fn         dlist_pop_head
 * @brief      Removes and returns the element stored at the beginning
 *             of the list.
 * @param[in]  list   Pointer to the list instance.
 * @return     Pointer to the removed data, or NULL if the list is empty.
 ******************************************************************************/
void *dlist_pop_head(DList *list);

/*****************************************************************************
 * @fn         dlist_pop_tail
 * @brief      Removes and returns the element stored at the end
 *             of the list.
 * @param[in]  list   Pointer to the list instance.
 * @return     Pointer to the removed data, or NULL if the list is empty.
 ******************************************************************************/
void *dlist_pop_tail(DList *list);

/*****************************************************************************
 * @fn         dlist_contains
 * @brief      Checks whether the list contains at least one element that
 *             matches the given criteria, using a user-provided callback.
 * @param[in]  list      Pointer to the list instance.
 * @param[in]  criteria  Pointer to the user-provided comparison data.
 * @param[in]  match     Function used to compare node_data vs criteria.
 * @return     true if a matching element is found, false otherwise.
 ******************************************************************************/
bool dlist_contains(const DList *list, const void *criteria, dlist_match_fn match);

#ifdef __cplusplus
} /* extern "C" */
#endif

/*===========================================================================*
 * Exported C++ Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add pure C++ function prototypes here.

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* DLIST_H */
