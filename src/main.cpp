/*===========================================================================*/
/**
 * @file main.cpp
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * You are given a string of space separated numbers, and have to return the highest and lowest number.
 * 
 * Examples
 * Input: "1 2 3 4 5"   =>  Output: "5 1"
 * Input: "1 2 -3 4 5"  =>  Output: "5 -3"
 * Input: "1 9 3 4 -5"  =>  Output: "9 -5"
 * Notes
 * All numbers are valid Int32, no need to validate them.
 * There will always be at least one number in the input string.
 * Output string must be two numbers separated by a single space, and highest number is first.
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
#include "fsm.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

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
    // int *actual = array_diff(arr1, ARRAY_LENGTH(arr1), arr2, ARRAY_LENGTH(arr2), &length);

    // printf("{ ");
    // for (size_t i = 0; i < length; i++)
    //     printf("%d%s", actual[i], (i == length - 1) ? "" : ", ");
    // printf(" }");
    
    // free(actual);

    std::cout << "=== Start ===" << std::endl;
    fsm_example();
    std::cout << "===  End  ===" << std::endl;
    return 0;
}
