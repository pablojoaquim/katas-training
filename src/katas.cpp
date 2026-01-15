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
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

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

/*****************************************************************************
 * Name         find_outlier
 * Description  Find The Parity Outlier. The array is either entirely comprised
 *              of odd integers or entirely comprised of even integers except
 *              for a single integer N
 *****************************************************************************/
int find_outlier(const int *values, size_t count)
{
    int even_counter = 0;
    int odd_counter = 0;
    int possible_even_outlier = 0;
    int possible_odd_outlier = 0;
    int outlier = 0;

    // Check if the input array is even or odd
    for (int i=0; i<count; i++)
    {
        if(0 == (values[i] % 2))
        {   
            possible_even_outlier = values[i];  // Store the last even number detected
            even_counter++;
        }
        else
        {
            possible_odd_outlier = values[i];   // Store the last odd number detected
            odd_counter++;
        }
    }

    if(even_counter == 1)
    {
        outlier = possible_even_outlier;
    }
    else
    {
        outlier = possible_odd_outlier;
    }
    
    printArr(outlier, count, (int *)values);
    return outlier;
}
