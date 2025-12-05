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
 * The Opaque pattern is a variation of the Object pattern in which the internal
 * data structure of the object is completely hidden from the user. Only a
 * forward declaration of the type is exposed in this header, preventing any
 * external code from accessing or depending on the internal layout of the
 * object.
 * Memory ownership remains with the user: the user is responsible for allocating
 * enough memory for the opaque object (typically using opaque_size() to obtain
 * the required size), and is also responsible for calling opaque_init() and
 * opaque_deinit() to properly construct and destruct the object.
 * The main advantages of this pattern are:
 *   - Encapsulation: the internal fields of the object are fully private.
 *   - ABI stability: changes to the internal structure do not affect users.
 *   - Controlled initialization: only the exposed functions can manipulate the
 *     internal state.
 *
 * Typical usage:
 *      struct opaque *obj = malloc(opaque_size());
 *      opaque_init(obj);
 *      opaque_set_data(obj, 123);
 *      uint32_t v = opaque_get_data(obj);
 *      opaque_deinit(obj);
 *      free(obj);
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

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* OBJECT_H */
