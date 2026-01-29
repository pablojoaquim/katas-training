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
 * @fn         power_optimized
 * @brief      Optimized Divide and Conquer Approach (Exponentiation by Squaring)
 * @param [in] base
 * @param [in] exp
 * @return     base^exp
 ******************************************************************************/
double power_optimized(double base, int exp);

/*****************************************************************************
 * @fn         who_is_winner
 * @brief      This is a gameplay for Connect Four. It receives the list of
 *             movements from each player, and determines the winner.
 * @param [in] pieces_position_list - The list of movements of the game in the form:
 *              std::vector<std::string> pieces_position_list
 *              {
 *                "A_Red",
 *                "B_Yellow",
 *                "A_Red",
 *                "B_Yellow",
 *                "A_Red",
 *                "B_Yellow",
 *                "G_Red",
 *                "B_Yellow"
 *              }
 * @return     "Yellow", "Red" or "Draw" accordingly
 ******************************************************************************/
/*****************************************************************************
 * Name         who_is_winner
 * Description  
 *****************************************************************************/
std::string who_is_winner(std::vector<std::string> pieces_position_list);

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* KATAS_H */
