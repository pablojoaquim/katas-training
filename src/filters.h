#ifndef FILTERS_H
#define FILTERS_H

/*===========================================================================*/
/**
 * @file filters.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION: API for the Filters module
 *
 * @todo Add full description here
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
 * Header Files (Common to C and C++)
 *===========================================================================*/

#ifdef __cplusplus
/*===========================================================================*
 * Header Files (C++ only)
 *===========================================================================*/
#include <iostream>
#include <vector>
#endif

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Classes (C++ only)
 *===========================================================================*/
#ifdef __cplusplus
class FIRFilter
{
private:
    std::vector<float> coeffs;
    std::vector<float> buffer;
    int index;

public:
    FIRFilter(const std::vector<float>& coefficients)
        : coeffs(coefficients),
          buffer(coefficients.size(), 0.0f),
          index(0)
    {}
    float filter(float input);
};

class Biquad
{
private:

    float a1, a2;
    float b0, b1, b2;

    float x1;
    float x2;

    float y1;
    float y2;

public:

    Biquad(float B0, float B1, float B2,
           float A1, float A2);

    float filter(float x);
};

#endif

/*===========================================================================*
 * Exported C Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
    // @todo: Add pure C function prototypes here.

#ifdef __cplusplus
} /* extern "C" */
#endif

/*===========================================================================*
 * Exported C++ Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add pure C++ function prototypes here.

/*****************************************************************************
 * @fn         encode
 * @brief      Takes a string and encode it
 * @param [in] p_what - The string to encode
 * @return     The encoded string
 ******************************************************************************/


#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* FILTERS_H */
