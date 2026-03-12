/*===========================================================================*/
/**
 * @file filters.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Digital filtering
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
#include "filters.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
// #define NDEBUG

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
 * Name         Methods declaration
 *****************************************************************************/

float FIRFilter::filter(float input)
{
    buffer[index] = input;

    float output = 0.0f;
    int buf_index = index;

    for (size_t i = 0; i < coeffs.size(); i++)
    {
        output += coeffs[i] * buffer[buf_index];

        if (buf_index == 0)
            buf_index = buffer.size() - 1;
        else
            buf_index--;
    }

    index++;
    if (index >= buffer.size())
        index = 0;

    return output;
}

Biquad::Biquad(float B0, float B1, float B2,
               float A1, float A2)
{
    b0 = B0;
    b1 = B1;
    b2 = B2;

    a1 = A1;
    a2 = A2;

    x1 = 0;
    x2 = 0;

    y1 = 0;
    y2 = 0;
}

float Biquad::filter(float x)
{
    float y =
        b0 * x +
        b1 * x1 +
        b2 * x2 -
        a1 * y1 -
        a2 * y2;

    x2 = x1;
    x1 = x;

    y2 = y1;
    y1 = y;

    return y;
}
