/*===========================================================================*/
/**
 * @file main.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Add a description here
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
#include <iostream>
#include <memory>
#include <string>
#include <cstdint>
#include "katas.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define NumElems(arr) (sizeof(arr) / sizeof((arr)[0]))

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
extern "C"
{
}

/*****************************************************************************
 * @fn         main
 * @brief      The main entry point
 * @param [in] void
 * @return     0 -success, -1 -Error
 *****************************************************************************/
int main(int argc, char *argv[])
{
    // const int arr1[] = {1, 2,3,4,5,6,6,7,8,9};
    // const int arr2[] = {1};

    // size_t length;
    // int *actual = camelCaseBreaker(arr1, ARRAY_LENGTH(arr1), arr2, ARRAY_LENGTH(arr2), &length);

    // printf("{ ");
    // for (size_t i = 0; i < length; i++)
    //     printf("%d%s", actual[i], (i == length - 1) ? "" : ", ");
    // printf(" }");

    // free(actual);

    std::cout << "=== Start ===" << std::endl;
    // int array[] = {9, 0, 0, 9, 1, 2, 0, 1, 0, 1, 0, 3, 0, 1, 9, 0, 0, 0, 0, 9};
    int array[] = {0, 1, 0, 2, 0, 3, 4, 5};
    int len = NumElems(array);
    move_zeros(len, array);
    for (int i = 0; i < len; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "===  End  ===" << std::endl;
    return 0;
}
