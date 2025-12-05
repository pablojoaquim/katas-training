#ifndef SINGLETON_H
#define SINGLETON_H

/*===========================================================================*/
/**
 * @file singleton.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Simple Singleton pattern implementation in C.
 *
 * This pattern guarantees that only one instance of an object exists and provides
 * a global point of access to it. In C, this is typically implemented by storing
 * a static instance inside the implementation (.c file), hiding the data from the
 * user and exposing a stateless API.
 *
 * Unlike the object or opaque patterns, the user never allocates memory or creates
 * an instance. The instance is created automatically the first time it is accessed.
 *
 * Usage example:
 *      singleton_set_value(42);
 *      int v = singleton_get_value();
 *      printf("Value = %d\n", v);
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
 */
/*===========================================================================*/

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
/**
 * @brief Sets a value inside the singleton instance.
 */
void singleton_set_value(uint32_t value);

/**
 * @brief Retrieves the internal value stored in the singleton instance.
 */
uint32_t singleton_get_value(void);


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
#endif /* SINGLETON_H */

