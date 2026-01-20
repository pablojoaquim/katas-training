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

unsigned int from_roman_conversion(unsigned char c)
{
    unsigned int ret = 0;
    switch (c)
    {
    case 'I':
        ret = 1;
        break;
    case 'V':
        ret = 5;
        break;
    case 'X':
        ret = 10;
        break;
    case 'L':
        ret = 50;
        break;
    case 'C':
        ret = 100;
        break;
    case 'D':
        ret = 500;
        break;
    case 'M':
        ret = 1000;
        break;
    default:
        break;
    }
    return ret;
}

/*****************************************************************************
 * Name         from_roman
 * Description  Convert a roman number in the string to an integer
 *****************************************************************************/
unsigned from_roman(const char *roman)
{
    int len = strlen(roman);
    int i = 0;
    int curr_number = 0;
    int next_number = 0;
    int number = 0;
    for (i = 0; i < len; i++)
    {
        curr_number = from_roman_conversion(roman[i]);
        // printf("curr_number: -- %d --- \n", curr_number);
        if ((i + 1) < len)
        {
            next_number = from_roman_conversion(roman[i + 1]);
            // printf("next_number: -- %d --- \n", next_number);
            if (curr_number >= next_number)
                number += curr_number;
            else
            {
                number += next_number - curr_number;
                i++;
            }
        }
        else
        {
            number += curr_number;
        }
    }
    return number;
}

unsigned int to_roman_conversion(char digitx1, char digitx5, char digitx10, unsigned int number, char *roman)
{
    unsigned int pos = 0;
    switch (number)
    {
    case 1:
        roman[pos++] = digitx1;
        break;
    case 2:
        roman[pos++] = digitx1;
        roman[pos++] = digitx1;
        break;
    case 3:
        roman[pos++] = digitx1;
        roman[pos++] = digitx1;
        roman[pos++] = digitx1;
        break;
    case 4:
        roman[pos++] = digitx1;
        roman[pos++] = digitx5;
        break;
    case 5:
        roman[pos++] = digitx5;
        break;
    case 6:
        roman[pos++] = digitx5;
        roman[pos++] = digitx1;
        break;
    case 7:
        roman[pos++] = digitx5;
        roman[pos++] = digitx1;
        roman[pos++] = digitx1;
        break;
    case 8:
        roman[pos++] = digitx5;
        roman[pos++] = digitx1;
        roman[pos++] = digitx1;
        roman[pos++] = digitx1;
        break;
    case 9:
        roman[pos++] = digitx1;
        roman[pos++] = digitx10;
        break;
    default:
        break;
    }
    return pos;
}

/*****************************************************************************
 * Name         to_roman
 * Description  Convert a roman number as integer to a string
 *****************************************************************************/
void to_roman(unsigned number, char *roman)
{
    unsigned int m = 0;
    unsigned int c = 0;
    unsigned int d = 0;
    unsigned int u = 0;

    m = number / 1000;
    c = (number % 1000) / 100;
    d = (number % 100) / 10;
    u = number % 10;
    // printf("m: -- %d --- \n", m);
    // printf("c: -- %d --- \n", c);
    // printf("d: -- %d --- \n", d);
    // printf("u: -- %d --- \n", u);

    unsigned int pos = 0;
    pos += to_roman_conversion('M', 'M', 'M', m, roman + pos);
    pos += to_roman_conversion('C', 'D', 'M', c, roman + pos);
    pos += to_roman_conversion('X', 'L', 'C', d, roman + pos);
    pos += to_roman_conversion('I', 'V', 'X', u, roman + pos);

    roman[pos] = '\0';
}