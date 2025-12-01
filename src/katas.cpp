/*===========================================================================*/
/**
 * @file katas.cpp
 *
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
 * Name         array_diff
 * Description  Computes the difference between two lists.
 *              The length of the returned array goes to *z, and the returned 
 *              array shall be freed by the caller
 *****************************************************************************/
int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z)
{
    int index;
    int working_index = 0;
    int* working_arr = (int*) malloc(n1 * sizeof(int));
    // Check for lack of available memory
    if(NULL == (working_arr))
    {
        *z = 0;
        return NULL;
    }

    // Move thorugh the arr1
    for (index=0; index<n1; index++)
    {
        bool found = false;
        // Check if the current element is present in arr2 
        for (int j=0; j<n2; j++)
        {
            if(arr1[index] == arr2[j])
            {
                found=true;
                break;
            }
        }
        if(found==false)
        {
            working_arr[working_index] = arr1[index];
            working_index++;
        }
    }
    
    // Resize the array before returning
    working_arr = (int*)realloc(working_arr, sizeof(int) * working_index);
    *z = working_index;
    return working_arr;
}
