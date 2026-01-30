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
#include <unordered_map>

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
extern "C"
{
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
 * @fn         partsSum
 * @brief      The function parts_sums will take as parameter a list 
 *             and return a list of the sums of its parts
 * @param [in] ls - The input list
 * @return     The list with the sum of the parts of the input.
 *             
 * Let us consider this example (array written in general format):
 *             ls = [0, 1, 3, 6, 10]
 *             
 *             Its following parts:
 *             
 *             ls = [0, 1, 3, 6, 10]
 *             ls = [1, 3, 6, 10]
 *             ls = [3, 6, 10]
 *             ls = [6, 10]
 *             ls = [10]
 *             ls = []
 * The corresponding sums are (put together in a list): [20, 20, 19, 16, 10, 0]
 ******************************************************************************/
std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls);

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* KATAS_H */
