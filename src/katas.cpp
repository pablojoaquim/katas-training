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

 void printArr (int curr, size_t len, int *arr)
 {
    printf("-- %d ---", curr);
    for (size_t i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
 }

/*****************************************************************************
 * Name         human_readable_time
 * Description  Takes a non-negative integer (seconds) as input and returns 
 *              the time in a human-readable format (HH:MM:SS)
 *****************************************************************************/
char *human_readable_time (unsigned seconds, char *time_string)
{
    int hh = seconds/3600;
    int mm = (seconds%3600)/60;
    int ss = (seconds%3600)%60;
    time_string[0] = hh/10 + '0';
    time_string[1] = hh%10 + '0';
    time_string[2] = ':';
    time_string[3] = mm/10 + '0';
    time_string[4] = mm%10 + '0';
    time_string[5] = ':';    
    time_string[6] = ss/10 + '0';
    time_string[7] = ss%10 + '0';
    time_string[8] = '\0';
	return time_string;
}
