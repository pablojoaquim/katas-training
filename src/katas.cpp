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
#include <algorithm>
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
 * Name         encode
 * Description  Takes a string and encode it
 *****************************************************************************/
std::string encode(const std::string &p_what)
{
    // std::string decode_a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // std::string encode_a = "bdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHa";
    // std::string decode_b = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    // std::string encode_b = "dhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHab";
    // std::string decode_c = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";
    // std::string encode_c = "flxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIc";
    // std::string decode_A = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    // std::string encode_A = "1OoD70MkvRuPqHabdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA";
    // std::string decode_abc =   "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // std::string encode_abc =   "bhx,zWyLZ3pOGIhzeXTYtjAaDWiO8miYH 8Uk4XMwc1c,QXBTeK8";
    // //babb -> ddpF

    std::string cipher = "bdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHa";
    std::string output;

    for (int i = 0; i < p_what.length(); i++)
    {
        size_t start = cipher.find(p_what[i]);
        if (start == std::string::npos)
        {
            output.push_back(p_what[i]);
        }
        else
        {
            size_t idx = (start + i + 1) % cipher.size();
            output.push_back(cipher[idx]);
        }
    }
    return output;
}

/*****************************************************************************
 * Name         decode
 * Description  Takes an encoded string and deecode it
 *****************************************************************************/
std::string decode(const std::string &p_what)
{
    std::string cipher = "aHqPuRvkM07DoO1AU49EW5CVxlfcIY6.? GXyTwS3BngKZzmNtjeJriLsQ28,Fphdb";
    std::string output;

    for (int i = 0; i < p_what.length(); i++)
    {
        size_t start = cipher.find(p_what[i]);
        if (start == std::string::npos)
        {
            output.push_back(p_what[i]);
        }
        else
        {
            size_t idx = (start + i + 1) % cipher.size();
            output.push_back(cipher[idx]);
        }
    }
    return output;
}
