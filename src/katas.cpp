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
 * Name         who_is_winner
 * Description  This is a gameplay for Connect Four. It receives the list of
 *              movements from each player, and determines the winner.
 *****************************************************************************/
std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
    constexpr int ROWS = 6;
    constexpr int COLUMNS = 7;
    constexpr int CONNECT = 4;
    char positions[ROWS][COLUMNS] = {};
    int row_position[COLUMNS] = {0};

    // Iterate thorugh the input
    for (std::string elem : pieces_position_list)
    {
        int column = elem[0] - 'A'; // Get the column played
        row_position[column]++;     // Increment the number of pieces in the column (which is the row!)
        char player = elem[2];      // Could be 'Y' or 'R'
        positions[row_position[column] - 1][column] = player;
    }

#ifndef NDEBUG
    // Printout the game
    // (this is not necessary, is just for debugging)
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            switch (positions[row][col])
            {
            case 'Y':
                printf("Y ");
                break;
            case 'R':
                printf("R ");
                break;
            case 0:
                printf("* ");
                break;
            default:
                printf("E "); // Error, undefined value
                break;
            }
        }
        printf("\n");
    }
    printf("\n");
#endif

    // Iterate through the columns to look for a continous group of pieces of one color in a row
    for (int row = 0; row < ROWS; row++)
    {
        // The column winner could be (at least) 0123 or 1234 or 2345 or 3456
        for (int col = 0; col <= COLUMNS - CONNECT; col++)
        {
            if ((positions[row][col + 0] != 0) &&
                (positions[row][col + 0] == positions[row][col + 1]) &&
                (positions[row][col + 0] == positions[row][col + 2]) &&
                (positions[row][col + 0] == positions[row][col + 3]))
            {
                printf("row\n");
                return (positions[row][col + 0] == 'Y') ? "Yellow" : "Red";
            }
        }
    }

    // Iterate through the columns to look for a continous group of pieces of one color in a column
    for (int col = 0; col < COLUMNS; col++)
    {
        // The row winner could be (at least) 0123 or 1234 or 2345
        for (int row = 0; row <= ROWS - CONNECT; row++)
        {
            if ((positions[row + 0][col] != 0) &&
                (positions[row + 0][col] == positions[row + 1][col]) &&
                (positions[row + 0][col] == positions[row + 2][col]) &&
                (positions[row + 0][col] == positions[row + 3][col]))
            {
                printf("column\n");
                return (positions[row + 0][col] == 'Y') ? "Yellow" : "Red";
            }
        }
    }

    // Iterate through the descendant diagonal
    for (int row = CONNECT - 1; row < ROWS; row++)
    {
        for (int col = 0; col <= COLUMNS - CONNECT; col++)
        {
            if (positions[row][col] != 0 &&
                positions[row][col] == positions[row - 1][col + 1] &&
                positions[row][col] == positions[row - 2][col + 2] &&
                positions[row][col] == positions[row - 3][col + 3])
            {
                printf("descendant\n");
                return (positions[row][col] == 'Y') ? "Yellow" : "Red";
            }
        }
    }

    // Iterate through the ascendant diagonal
    for (int row = 0; row <= ROWS - CONNECT; row++)
    {
        for (int col = 0; col <= COLUMNS - CONNECT; col++)
        {
            if (positions[row][col] != 0 &&
                positions[row][col] == positions[row + 1][col + 1] &&
                positions[row][col] == positions[row + 2][col + 2] &&
                positions[row][col] == positions[row + 3][col + 3])
            {
                printf("ascendant\n");
                return (positions[row][col] == 'Y') ? "Yellow" : "Red";
            }
        }
    }

    return "Draw";
}

/*****************************************************************************
 * Name         who_is_winner_play_by_play
 * Description  Same as who_is_winner but the evaluation is play by play, instead
 *              of evaluate the final winner with the whole final view of the board.
 *              The issue could happen if someone adds new pieces after the game has finished.
 *****************************************************************************/
std::string who_is_winner_play_by_play(std::vector<std::string> pieces_position_list)
{
    constexpr int ROWS = 6;
    constexpr int COLUMNS = 7;
    constexpr int CONNECT = 4;

    char board[ROWS][COLUMNS] = {};
    int height[COLUMNS] = {};

    auto inside = [&](int r, int c) {
        return r >= 0 && r < ROWS && c >= 0 && c < COLUMNS;
    };

    for (const std::string& move : pieces_position_list)
    {
        int col = move[0] - 'A';
        char player = (move.find("Red") != std::string::npos) ? 'R' : 'Y';

        int row = height[col]++;
        board[row][col] = player;

        // Directions: horizontal, vertical, two diagonals
        const int directions[4][2] = {
            {0, 1},
            {1, 0},
            {1, 1},
            {1, -1}
        };

        for (auto& d : directions)
        {
            int count = 1;

            // Forward
            for (int k = 1; k < CONNECT; k++)
            {
                int r = row + d[0] * k;
                int c = col + d[1] * k;
                if (!inside(r, c) || board[r][c] != player)
                    break;
                count++;
            }

            // Backward
            for (int k = 1; k < CONNECT; k++)
            {
                int r = row - d[0] * k;
                int c = col - d[1] * k;
                if (!inside(r, c) || board[r][c] != player)
                    break;
                count++;
            }

            if (count >= CONNECT)
                return (player == 'R') ? "Red" : "Yellow";
        }
    }

    return "Draw";
}
