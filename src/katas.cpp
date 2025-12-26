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


/*****************************************************************************
 * Name         camelCaseBreaker
 * Description  Break up camel casing strings, using a space between words.
 *              The returned buffer should be dynamically allocated and 
 *              will be freed by a callerr
 *****************************************************************************/
char* camelCaseBreaker(const char *camelCase) 
{
    int len = strlen(camelCase);

    // Goes through the input string and count the number of upper case letters
    int upperCaseCnt = 0;
    for(int i=0; i<len; i++)
    {
        if(camelCase[i]>='A' && camelCase[i]<='Z' && i!=0)
        upperCaseCnt++;
    }

    // Prepare the output string
    char* str = (char*)malloc(len+upperCaseCnt+1);
    
    // Simple solution but needs a big buffer which probably we're not going to use
    // char* str = (char*)malloc(200);
    int pos = 0;
    for(int i=0; i<len;i++)
    {
        if(camelCase[i]>='A' && camelCase[i]<='Z' && i!=0)
        {
            str[pos] = ' ';
            pos++;
        }
        str[pos] = camelCase[i];
        pos++;    
    }
    str[pos]='\0';
    return (str);
}
