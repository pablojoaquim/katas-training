/*===========================================================================*/
/**
 * @file katas.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Develop the code to solve the kata in this file
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
 * Header Files
 *===========================================================================*/
#include <cstdint>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "katas.h"
#include <vector>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
// #define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define QUEUE_SIZE 50

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef int q_elem;

typedef struct queue
{
    q_elem buf[QUEUE_SIZE];
    int head;
    int tail;
    int count;
} queue_t;

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/
// int working_arr[100];

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

void printArr(int curr, size_t len, int *arr)
{
    printf("-- %d --- ", curr);
    for (size_t i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void q_init(queue_t *q)
{
    q->head = q->tail = q->count = 0;
}

bool q_is_empty(queue_t *q)
{
    return (0 == q->count);
}

bool q_is_full(queue_t *q)
{
    return (QUEUE_SIZE == q->count);
}

bool q_push(queue_t *q, q_elem elem)
{
    if (q_is_full(q))
        return false;
    q->buf[q->tail] = elem;
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    q->count++;
    return true;
}

bool q_pop(queue_t *q, q_elem *out)
{
    if (q_is_empty(q))
        return false;
    *out = q->buf[q->head];
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->count--;
    return true;
}

/*****************************************************************************
 * Name         power_optimized
 * Description  Optimized Divide and Conquer Approach (Exponentiation by Squaring)
 *****************************************************************************/
double power_optimized(double base, int exp)
{
    if (exp == 0)
        return 1;
    // Handle negative exponents by taking the reciprocal
    if (exp < 0)
    {
        base = 1.0 / base;
        exp = -exp;
    }
    double result = 1.0;
    while (exp > 0)
    {
        // std::cout << "result: " << result << " - base: " << base << " - exp: " << exp << std::endl;
        // If exponent is odd, multiply result by base
        if (exp % 2 == 1)
        {
            result *= base;
        }
        base *= base; // Square the base
        exp /= 2;     // Halve the exponent
    }
    // std::cout << "result: " << result << std::endl;
    return result;
}

/*****************************************************************************
 * Name         Class SnakesLadders
 * Description  Snakes and Ladders is an ancient Indian board game regarded
 *              today as a worldwide classic. It is played by two or more
 *              players on a game board with numbered, gridded squares.
 *              A number of "ladders" and "snakes" are pictured on the board,
 *              each connecting two specific squares.
 *****************************************************************************/
SnakesLadders::SnakesLadders()
{
    this->player = 0; // Player 1 starts and alternates with player 2.
    this->pos[0] = 0; // Player 1 starts at square 0
    this->pos[1] = 0; // Player 2 starts at square 0
    this->gameover = false;
};

const std::unordered_map<int, int> SnakesLadders::jumps =
    {
        // ladders
        {2, 38},
        {7, 14},
        {8, 31},
        {15, 26},
        {21, 42},
        {28, 84},
        {36, 44},
        {51, 67},
        {71, 91},
        {78, 98},
        {87, 94},
        // snakes
        {16, 6},
        {49, 11},
        {46, 25},
        {64, 60},
        {62, 19},
        {74, 53},
        {89, 68},
        {95, 75},
        {99, 80},
        {92, 88}};

/*****************************************************************************
 * Name         play
 * Description  Call this method with the value of dice1 and dice2, evaluate the
 *              current player move and return the result in the board.
 *****************************************************************************/
std::string SnakesLadders::play(int dice1, int dice2)
{
    std::string ret;

    if (true == this->gameover)
    {
        ret = "Game over!";
        return ret;
    }

    // Evaluate the new player position
    this->pos[this->player] += dice1 + dice2;

    // If the player roll too high, "bounces" off the last square and moves back
    if (this->pos[this->player] > 100)
    {
        this->pos[this->player] = 100 - (this->pos[this->player] - 100);
    }

    // Evaluate the move through snakes and ladders
    auto move = jumps.find(this->pos[this->player]);
    if (move != jumps.end())
    {
        this->pos[this->player] = move->second;
    }
    // Instead of the map a switch-case could be use
    // switch (this->pos[this->player])
    // {
    // case 2: // ladder
    //     this->pos[this->player] = 38;
    //     break;
    // case 7: // ladder
    //     this->pos[this->player] = 14;
    //     break;
    // case 8: // ladder
    //     this->pos[this->player] = 31;
    //     break;
    // case 15: // ladder
    //     this->pos[this->player] = 26;
    //     break;
    // case 21: // ladder
    //     this->pos[this->player] = 42;
    //     break;
    // case 28: // ladder
    //     this->pos[this->player] = 84;
    //     break;
    // case 36: // ladder
    //     this->pos[this->player] = 44;
    //     break;
    // case 51: // ladder
    //     this->pos[this->player] = 67;
    //     break;
    // case 78: // ladder
    //     this->pos[this->player] = 98;
    //     break;
    // case 71: // ladder
    //     this->pos[this->player] = 91;
    //     break;
    // case 87: // ladder
    //     this->pos[this->player] = 94;
    //     break;
    // case 16: // snake
    //     this->pos[this->player] = 6;
    //     break;
    // case 49: // snake
    //     this->pos[this->player] = 11;
    //     break;
    // case 46: // snake
    //     this->pos[this->player] = 25;
    //     break;
    // case 64: // snake
    //     this->pos[this->player] = 60;
    //     break;
    // case 62: // snake
    //     this->pos[this->player] = 19;
    //     break;
    // case 74: // snake
    //     this->pos[this->player] = 53;
    //     break;
    // case 89: // snake
    //     this->pos[this->player] = 68;
    //     break;
    // case 99: // snake
    //     this->pos[this->player] = 80;
    //     break;
    // case 95: // snake
    //     this->pos[this->player] = 75;
    //     break;
    // case 92: // snake
    //     this->pos[this->player] = 88;
    //     break;
    // default:
    //     break;
    // }

    // Evaluate winning the game (only if there's no more moves from that player)
    if (this->pos[this->player] == 100)
    {
        ret = "Player " + std::to_string(this->player + 1) + " Wins!";
        this->gameover = true;
    }
    else
    {
        ret = "Player " + std::to_string(this->player + 1) + " is on square " + std::to_string(this->pos[this->player]);
    }
    // If the dices are equals the player should play again,
    // if not move the turn to the other player
    if (dice1 != dice2)
    {

        // Move to the next player
        (this->player == 0) ? this->player = 1 : this->player = 0;
        // this->player = (this->player+1)%2;  // Another way, a little more complicated
    }

    return ret;
};
