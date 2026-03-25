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
#include <iostream>
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

class MembershipFunction
{
public:
    virtual float computeMembership(float x) const = 0;
    virtual ~MembershipFunction() = default;
};

class TriangularMembershipFunction : public MembershipFunction
{
    float a, b, c;

public:
    TriangularMembershipFunction(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    float computeMembership(float x) const override
    {
        // Implement triangular membership function
        // case 1: outside the range
        if (x <= a || x >= c)
            return 0.0f;

        // case 2: peak
        if (x == b)
            return 1.0f;

        // case 3: positive slope
        if (x < b)
            return (x - a) / (b - a);

        // case 4: negative slope
        return (c - x) / (c - b);
    }
};

class TrapezoidalMembershipFunction : public MembershipFunction
{
    float a, b, c, d;

public:
    TrapezoidalMembershipFunction(float a, float b, float c, float d)
        : a(a), b(b), c(c), d(d) {}

    float computeMembership(float x) const override
    {
        // Outside the range
        if (x <= a || x >= d)
            return 0.0f;

        // 2. plateau
        if (x >= b && x <= c)
            return 1.0f;

        // Avoid division by zero
        if (b == a)
            return 0.0f;

        // 3. positive slope
        if (x < b)
            return (x - a) / (b - a);

        // Avoid division by zero
        if (d == c)
            return 0.0f;

        // 4. negative slope
        return (d - x) / (d - c);
    }
};

class FuzzyType
{
    std::string name;                                      // temperature
    float minValue;                                        // 0.0
    float maxValue;                                        // 100.0
    std::map<std::string, MembershipFunction *> fuzzySets; // cold, warm, hot

public:
    FuzzyType(std::string name, float minValue, float maxValue)
    {
        this->name = name;
        this->minValue = minValue;
        this->maxValue = maxValue;
    }

    void addFuzzySet(const std::string &setName, MembershipFunction *membershipFunction)
    {
        fuzzySets.emplace(setName, membershipFunction);
    }

    std::map<std::string, float> calcFuzzyValues(float input) const
    {
        std::map<std::string, float> fuzzyValues;
        for (const auto &[name, membershipFunction] : fuzzySets)
        {
            fuzzyValues[name] = membershipFunction->computeMembership(input);
        }
        return fuzzyValues;
    }
};

class FuzzyValues
{
    const FuzzyType &fuzzyType;
    float input;
    std::map<std::string, float> fuzzyValues;

public:
    FuzzyValues(const FuzzyType &fuzzyType, float in) : fuzzyType(fuzzyType), input(in)
    {
    }

    void setInput(float in)
    {
        input = in;
    }

    void printFuzzyValues() const
    {
        for (const auto &[name, value] : fuzzyValues)
        {
            std::cout << "Fuzzy value for " << name << ": " << value << std::endl;
        }
    }

    void fuzzify()
    {
        fuzzyValues = fuzzyType.calcFuzzyValues(input);
    }
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
