#ifndef OPAQUE_H
#define OPAQUE_H

/*===========================================================================*/
/**
 * @file opaque.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * API for the Opaque design pattern
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
// The public interface for the opaque object is defined in a very similar way to the object
// pattern, with the main difference that the structure itself is only declared in the public header
// (without the data fields) and then actually declared in the private C file.
struct opaque; // just a declaration

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

// init and deinit
int opaque_init(struct opaque *self);
int opaque_deinit(struct opaque *self);

// methods that operate on an opaque
void opaque_set_data(struct opaque *self, uint32_t data);
uint32_t opaque_get_data(struct opaque *self);

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
