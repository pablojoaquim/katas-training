#ifndef OBJECT_H
#define OBJECT_H

/*===========================================================================*/
/**
 * @file object.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * API for the Object design pattern
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
#include <stdint.h>

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
// The key in object pattern is that the user is responsible for allocation of objects.
// User must either allocate the object on stack of the main thread or as part of 
// another object which will be using our object
struct object
{
    uint32_t variable;
    uint32_t flags;
};

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

int object_init(struct object *self);
int object_deinit(struct object *self);

#ifdef __cplusplus
} /* extern "C" */
#endif

/*===========================================================================*
 * Exported C++ Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add pure C++ function prototypes here.

/*****************************************************************************
 * @fn         array_diff
 * @brief      Computes the difference between two lists.
 *             Remove all occurrences of elements from the first list (arr1)
 *             that are present in the second list (arr2).
 *             The order of elements in the first list is preserved in the result.
 * @param [in] arr1
 * @param [in] arr2
 * @return     The resulted array. This array shall be freed by the caller.
 ******************************************************************************/

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* OBJECT_H */
