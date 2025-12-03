#ifndef DICT_H
#define DICT_H

/*===========================================================================*/
/**
 * @file dict.h
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * API for the Dictionary implementation based in hash tables
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
/*****************************************************************************
 * @typedef    dict_free_fn
 * @brief      Callback used to free the used memory by data
 * @param[in]  data   Pointer to the data stored in the node.
 * @return     None
 ******************************************************************************/
typedef void (*dict_free_fn)(void *value);

typedef struct dict_item {
    char *key;
    void *value;
    struct dict_item *next;
} dict_item;

typedef struct {
    dict_item **buckets;
    size_t capacity;
    dict_free_fn free_fn;
} dict;

/*****************************************************************************
 * @typedef    dict_iter_fn
 * @brief      Callback called by the foreach function to analyze each element
 * @param[in]  data   Pointer to the data stored in the list node.
 * @return     None
 ******************************************************************************/
typedef void (*dict_iter_fn)(const char *key, void *value);

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
 * @fn         dict_create
 * @brief      Creates a new dictionary with the specified capacity.
 * @param[in]  capacity  Initial number of buckets in the dictionary.
 * @param[in]  free_fn   Function to free values when removed or dictionary is freed.
 * @return     Pointer to the newly created dictionary, or NULL on failure.
 ******************************************************************************/
dict *dict_create(size_t capacity, dict_free_fn free_fn);

/*****************************************************************************
 * @fn         dict_set
 * @brief      Sets or updates the value associated with a key in the dictionary.
 * @param[in]  d      Pointer to the dictionary instance.
 * @param[in]  key    Null-terminated string key.
 * @param[in]  value  Pointer to the value to store.
 * @return     0 on success, non-zero on failure (e.g., memory allocation error).
 ******************************************************************************/
int dict_set(dict *d, const char *key, void *value);

/*****************************************************************************
 * @fn         dict_get
 * @brief      Retrieves the value associated with the given key.
 * @param[in]  d      Pointer to the dictionary instance.
 * @param[in]  key    Null-terminated string key.
 * @return     Pointer to the stored value, or NULL if key does not exist.
 ******************************************************************************/
void *dict_get(dict *d, const char *key);

/*****************************************************************************
 * @fn         dict_remove
 * @brief      Removes the entry associated with the specified key from the dictionary.
 *             Calls the free_fn on the value if it was provided during creation.
 * @param[in]  d      Pointer to the dictionary instance.
 * @param[in]  key    Null-terminated string key to remove.
 * @return     0 on success, non-zero if the key was not found.
 ******************************************************************************/
int dict_remove(dict *d, const char *key);

/*****************************************************************************
 * @fn         dict_free
 * @brief      Frees the dictionary and all its contents.
 *             Calls the free_fn on each value if it was provided during creation.
 * @param[in]  d      Pointer to the dictionary instance.
 * @return     None.
 ******************************************************************************/
void dict_free(dict *d);

/*****************************************************************************
 * @fn         dict_foreach
 * @brief      Iterates over all elements stored in the dict
 *             and invokes the supplied callback for each node's data.
 * @param[in]  list   Pointer to the dict instance.
 * @param[in]  fn     Function to be executed for each node; receives node data.
 * @return     None.
 ******************************************************************************/
void dict_foreach(dict *d, dict_iter_fn fn);

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
#endif /* DICT_H */
