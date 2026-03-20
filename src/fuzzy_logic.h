#ifndef FUZZY_LOGIC_H
#define FUZZY_LOGIC_H

/*===========================================================================*/
/**
 * @file fuzzy_logic.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2026 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION: API for the Fuzzy Logic module
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
#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <memory>
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

class LinguisticVariable
{
    std::string name;   // temperature
    float minValue;     // 0.0
    float maxValue;     // 100.0
    std::map<std::string, MembershipFunction*> fuzzySets;  // cold, warm, hot

    void addFuzzySet(const std::string& setName, MembershipFunction* membershipFunction)
    {
        fuzzySets.emplace(setName, membershipFunction);
    }
};

class MembershipFunction
{
public:
    virtual float computeMembership(float x) const = 0;
    virtual ~MembershipFunction() = default;
};

class TriangularMembershipFunction : public MembershipFunction
{
    float points[3];

    float computeMembership(float x) const override
    {
        // Implement triangular membership function logic here
    }
};

class FuzzyEvaluation
{
    float inputValue;
    const LinguisticVariable& variable;
    std::map<std::string, float> fuzzyValues;
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

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* FUZZY_LOGIC_H */
