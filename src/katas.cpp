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

std::vector<std::string> swap(const std::string& in)
{
    // std::cout << "input: " << in << std::endl;
    if (in.length() == 1)
        return {in};

    std::vector<std::string> out;

    for (int i = 0; i < in.length(); i++)
    {
        std::string to_swap = in.substr(0, i) + in.substr(i + 1);
        // std::cout << "to_swap: " << to_swap << std::endl;

        std::vector<std::string> from_swap = swap(to_swap);

        for (int j = 0; j < from_swap.size(); j++)
        {
            // std::cout << "from_swap: " << from_swap[j] << std::endl;
            out.push_back(in[i] + from_swap[j]);
            // std::cout << "out: " << in[i] + from_swap[j] << std::endl;
        }
    }
    return out;
}

/*****************************************************************************
 * Name         nextBigger
 * Description  Takes a positive integer and returns the next bigger number
 *              that can be formed by rearranging its digits.
 *****************************************************************************/
long nextBigger(long n)
{
    long next_bigger = -1;

    std::string input = std::to_string(n);
    std::string output;
    // std::cout << "The input is: " << input << std::endl;

    std::vector<std::string> perms = swap(input);
    // std::vector<long> numbers;
    long number;

    for (const std::string &p : perms)
    {
        // std::cout << "permutation: " << p << std::endl;
        // numbers.push_back(std::stol(p));
        number = std::stol(p);

        if(number > n)
        {
            if(next_bigger!= -1)
            {
                if(number<next_bigger)
                {
                    next_bigger = number;
                }
            }
            else
            {
                next_bigger = number;
            }
        }
    }

    // // Sort the vector in ascending order
    // std::sort(numbers.begin(), numbers.end());

    // // Look for the next bigger number
    // for(int i=0; i<numbers.size(); i++)
    // {
    //     if(numbers.at(i) == n)
    //     {
    //         // Check if the bigger is the provided 
    //         // number, in such case will be the last 
    //         // in the sorted vector
    //         if(i<(numbers.size()-1))
    //         {
    //             if(numbers[i] != numbers[i+1])
    //             {
    //                 next_bigger = numbers[i+1];
    //                 break;
    //             }
    //         }                
    //     }
    // }

    return next_bigger;
}

/*****************************************************************************
 * Name         nextBigger_Permutation
 * Description  Takes a positive integer and returns the next bigger number
 *              that can be formed by rearranging its digits.
 *              Look from the right the next smaller digit than the one at the right side
 *              2 0 1 7
 *                  ↑ (1 is smaller than 7)
 *              Look from that numer the next bigger to the right and do the swap
 *              The next bigger is: 7
 *              Do the swap: 2071
 *****************************************************************************/
long nextBigger_Permutation(long n)
{
    std::string s = std::to_string(n);

    // 1. Encontrar el primer índice i tal que s[i] < s[i+1]
    int i = s.size() - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;

    if (i < 0)
        return -1; // ya es la permutación más grande

    // 2. Encontrar el dígito más chico a la derecha de i que sea mayor que s[i]
    int j = s.size() - 1;
    while (s[j] <= s[i])
        j--;

    // 3. Swap
    std::swap(s[i], s[j]);

    // 4. Ordenar el resto
    std::sort(s.begin() + i + 1, s.end());

    return std::stol(s);
}