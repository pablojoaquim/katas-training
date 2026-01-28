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
#include <math.h>
#include "katas.h"
#include <vector>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

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
 * Name         hamber
 * Description  Calc the minimum hamming n number.
 *              A hamming number is a positive integer of the form 2^i*3^j*5^k,
 *              for some non-negative integers i, j, and k.
 *                     Assert::That(hamber(1), Equals(1));
 *                     Assert::That(hamber(2), Equals(2));
 *                     Assert::That(hamber(3), Equals(3));
 *                     Assert::That(hamber(4), Equals(4));
 *                     Assert::That(hamber(5), Equals(5));
 *                     Assert::That(hamber(8), Equals(9));
 *                     Assert::That(hamber(11), Equals(15));
 *                     Assert::That(hamber(14), Equals(20));
 *                     Assert::That(hamber(17), Equals(27));
 *                     Assert::That(hamber(20), Equals(36));
 *                     Assert::That(hamber(23), Equals(48));
 *                     Assert::That(hamber(26), Equals(60));
 *                     Assert::That(hamber(29), Equals(75));
 *                     Assert::That(hamber(32), Equals(90));
 *                     Assert::That(hamber(35), Equals(108));
 *                     Assert::That(hamber(38), Equals(128));
 *                     Assert::That(hamber(41), Equals(150));
 *                     Assert::That(hamber(44), Equals(180));
 *                     Assert::That(hamber(47), Equals(216));
 *                     Assert::That(hamber(50), Equals(243));
 *                     Assert::That(hamber(53), Equals(270));
 *                     Assert::That(hamber(56), Equals(320));
 *                     Assert::That(hamber(59), Equals(375));
 *                     Assert::That(hamber(62), Equals(405));
 *****************************************************************************/
uint64_t hamber(int n)
{
    std::vector<uint64_t> H(n+1);
    H[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;

    for (int k = 1; k <= n; ++k)
    {
        uint64_t next2 = 2 * H[i2];
        uint64_t next3 = 3 * H[i3];
        uint64_t next5 = 5 * H[i5];

        uint64_t next = next2;
        if (next3 < next)
            next = next3;
        if (next5 < next)
            next = next5;
        H[k] = next;

        if (next == next2)
            ++i2;
        if (next == next3)
            ++i3;
        if (next == next5)
            ++i5;
    }

    return H[n-1];

    // int i, j, k;
    // uint64_t hamming_number = 1;
    // uint64_t hamming[3] = {1};
    // i = 0;
    // j = 0;
    // k = 0;
    // while (n-- > 1)
    // {
    //     // uint64_t possible1 = power_optimized(2, i+1) * power_optimized(3, j) * power_optimized(5, k);
    //     // uint64_t possible2 = power_optimized(2, i) * power_optimized(3, j+1) * power_optimized(5, k);
    //     // uint64_t possible3 = power_optimized(2, i) * power_optimized(3, j) * power_optimized(5, k+1);
    //     uint64_t possible1 = hamming[0] * 2;
    //     uint64_t possible2 = hamming[1] * 3;
    //     uint64_t possible3 = hamming[3] * 5;
    //     std::cout << "possible1: " << possible1 << std::endl;
    //     std::cout << "possible2: " << possible2 << std::endl;
    //     std::cout << "possible3: " << possible3 << std::endl;

    //     if( (possible1<possible2) && (possible1<possible3))
    //     {
    //         hamming[0] = possible1;
    //         hamming_number = possible1;
    //     }
    //     if( (possible2<possible1) && (possible2<possible3))
    //     {
    //         hamming[1] = possible2;
    //         hamming_number = possible2;
    //     }
    //     if( (possible3<possible1) && (possible3<possible2))
    //     {
    //         hamming[2] = possible3;
    //         hamming_number = possible3;
    //     }
    // }

    // return hamming_number;
}