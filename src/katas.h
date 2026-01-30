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

/*****************************************************************************
 * Name         Class SnakesLadders
 * Description  Snakes and Ladders is an ancient Indian board game regarded
 *              today as a worldwide classic. It is played by two or more
 *              players on a game board with numbered, gridded squares.
 *              A number of "ladders" and "snakes" are pictured on the board,
 *              each connecting two specific squares.
 *****************************************************************************/
class SnakesLadders
{
private:
    int player;
    int pos[2];
    bool gameover;
    static const std::unordered_map<int, int> jumps;

public:
    SnakesLadders();

    /*****************************************************************************
     * @fn         play
     * @brief      Call this method with the value of dice1 and dice2, evaluate the 
     *             current player move and return the result in the board.
     * @param [in] dice1 - Value of the dice
     * @param [in] dice2 - Value of the dice
     * @return     Return "Player n Wins!" where n is the winning player who has 
     *             landed on square 100 without any remaining moves left.
     *             Return "Game over!" if a move is attempted after any player has won.
     *             Otherwise, return "Player n is on square x", where n is the current 
     *             player and x is the square they are currently on.
     ******************************************************************************/
    std::string play(int dice1, int dice2);
};
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
 * @fn         power_optimized
 * @brief      Optimized Divide and Conquer Approach (Exponentiation by Squaring)
 * @param [in] base
 * @param [in] exp
 * @return     base^exp
 ******************************************************************************/
double power_optimized(double base, int exp);

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* KATAS_H */
