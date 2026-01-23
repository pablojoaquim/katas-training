#ifndef KATAS_H
#define KATAS_H

/*===========================================================================*/
/**
 * @file kata.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION: API for the Person module
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
#include <stddef.h>

#ifdef __cplusplus
/*===========================================================================*
 * Header Files (C++ only)
 *===========================================================================*/
#include <string>
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
extern "C" {
#endif
// @todo: Add pure C function prototypes here.

#ifdef __cplusplus
} /* extern "C" */
#endif

 /*===========================================================================*
 * Exported C++ Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add pure C++ function prototypes here.

/*****************************************************************************
 * @fn         narcissistic
 * @brief      A Narcissistic Number (or Armstrong Number) is a positive number 
 *             which is the sum of its own digits, each raised to the power of 
 *             the number of digits in a given base.
 *             For example, take 153 (3 digits), which is narcissistic:
 *             1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
 * @param [in] value - The value to check if is narcissist or not
 * @return     True - The value is narcissist, False - Other
 ******************************************************************************/
bool narcissistic( int value );
#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* KATAS_H */
