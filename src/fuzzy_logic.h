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

using FuzzySetName = std::string;
using LinguisticVariableName = std::string;

// MembershipFunction is an abstract base class for different types of membership functions (e.g., triangular, trapezoidal).
class MembershipFunction
{
public:
    virtual float computeMembership(float x) const = 0;
};

// TriangularMembershipFunction represents a triangular membership function defined by three parameters: a, b, and c.
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

// TrapezoidalMembershipFunction represents a trapezoidal membership function defined by four parameters: a, b, c, and d.
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

// FuzzySet represents the adjectives with a name and a membership function.
// For example, "hot" with a trapezoidal membership function.
class FuzzySet
{
    FuzzySetName name;
    MembershipFunction *mf;

public:
    FuzzySet(const FuzzySetName &name, MembershipFunction *mf) : name(name), mf(mf) {}

    std::string getName() const
    {
        return name;
    }

    double getMembership(double x) const
    {
        return mf->computeMembership(x);
    }
};

// LinguisticVariable represents a variable (e.g., temperature) that can have multiple fuzzy sets (e.g., cold, warm, hot).
class LinguisticVariable
{
    LinguisticVariableName name;
    double minValue;
    double maxValue;
    std::vector<FuzzySet> fuzzySets;

public:
    // Constructor initializes the linguistic variable with a name and a range of values.
    LinguisticVariable(LinguisticVariableName name, double minValue, double maxValue)
        : name(name), minValue(minValue), maxValue(maxValue) {}

    LinguisticVariableName getName() const
    {
        return name;
    }

    // addFuzzySet adds a new fuzzy set to the linguistic variable.
    // Each fuzzy set is defined by a name and a membership function.
    void addFuzzySet(const FuzzySetName &setName, MembershipFunction *mf)
    {
        fuzzySets.push_back({setName, mf});
    }

    // fuzzify takes a crisp input value and calculates the degree of membership
    // for each fuzzy set associated with the linguistic variable.
    std::map<FuzzySetName, double> fuzzify(double input) const
    {
        std::map<FuzzySetName, double> fuzzyValues;
        for (const auto &fuzzySet : fuzzySets)
        {
            fuzzyValues[fuzzySet.getName()] = fuzzySet.getMembership(input);
        }
        return fuzzyValues;
    }
};

// FuzzyRule represents a rule that consists of antecedents (conditions) and a consequent (result).
class FuzzyRule
{
    std::vector<std::pair<LinguisticVariable *, FuzzySetName>> antecedents; // e.g., temperature is hot
    std::pair<LinguisticVariable *, FuzzySetName> consequent;               // e.g., fan speed is high
public:
    // Constructor initializes the fuzzy rule with a list of antecedents and a single consequent.
    FuzzyRule(const std::vector<std::pair<LinguisticVariable *, FuzzySetName>> &antecedents, const std::pair<LinguisticVariable *, FuzzySetName> &consequent)
        : antecedents(antecedents), consequent(consequent) {};

    // getConsequent returns the consequent of the fuzzy rule, which is a 
    // pair of a linguistic variable and a fuzzy set name.
    std::pair<LinguisticVariable *, FuzzySetName> getConsequent() const
    {
        return consequent;
    }

    // evaluate takes a map of input values (e.g., {"temperature": {"hot": 0.8, "warm": 0.5}}) and calculates the
    // degree of truth for the rule's antecedents.
    double evaluate(const std::map<LinguisticVariableName, std::map<FuzzySetName, double>> &inputs) const
    {
        double activation = 1.0;

        for (const auto &antecedent : antecedents)
        {
            // For each antecedent, we look up the corresponding membership value from the inputs map.
            // We first find the linguistic variable in the inputs map using the variable name.
            // Then we find the fuzzy set within that variable using the set name.
            const LinguisticVariableName &varName = antecedent.first->getName();
            const FuzzySetName &setName = antecedent.second;

            // If the variable or set is not found in the inputs, we assume a membership of 0.0.
            auto varIt = inputs.find(varName);
            if (varIt == inputs.end())
                return 0.0;
            // If the variable is found, we look for the fuzzy set within that variable.
            // If the fuzzy set is not found, we also assume a membership of 0.0.
            auto setIt = varIt->second.find(setName);
            if (setIt == varIt->second.end())
                return 0.0;

            // We use the minimum membership value across all 
            // antecedents to determine the activation level of the rule.
            activation = std::min(activation, setIt->second);
        }

        return activation;
    }
};

class InferenceEngine
{
    std::vector<FuzzyRule> rules;
public:
    // addRule adds a new fuzzy rule to the inference engine.
    void addRule(const FuzzyRule &rule)
    {
        rules.push_back(rule);
    }
    // infer takes a map of input values and evaluates all the rules in the engine.
    // It returns a map of output values based on the consequents of the activated rules.
    std::map<LinguisticVariableName, std::map<FuzzySetName, double>> infer(const std::map<LinguisticVariableName, std::map<FuzzySetName, double>> &inputs) const
    {
        std::map<LinguisticVariableName, std::map<FuzzySetName, double>> outputs;

        for (const auto &rule : rules)
        {
            // For each rule, we evaluate its activation level based on the input values.
            double activation = rule.evaluate(inputs);
            if (activation > 0.0)
            {
                // If the rule is activated (i.e., activation > 0), we update the output values 
                // based on the rule's consequent.
                const auto &consequent = rule.getConsequent();
                // We use the maximum activation value for each output fuzzy set to combine the effects of multiple rules.
                outputs[consequent.first->getName()][consequent.second] = std::max(outputs[consequent.first->getName()][consequent.second], activation);
            }
        }
        return outputs;
    }
};

class Defuzzifier
{
public:
    // defuzzify takes a map of fuzzy output values and calculates a crisp output value.
    // For simplicity, we use the centroid method for defuzzification.
    double defuzzify(const std::map<FuzzySetName, double> &fuzzyValues, const std::vector<FuzzySet> &fuzzySets) const
    {
        double numerator = 0.0;
        double denominator = 0.0;

        for (const auto &fuzzySet : fuzzySets)
        {
            double membership = fuzzyValues.at(fuzzySet.getName());
            // For the centroid method, we assume the center of the fuzzy set is at the midpoint of its range.
            // In a real implementation, you would typically calculate the centroid based on the shape of the membership function.
            double centroid = (fuzzySet.getMembership(0) + fuzzySet.getMembership(1)) / 2.0; // Placeholder for actual centroid calculation
            numerator += membership * centroid;
            denominator += membership;
        }

        return (denominator == 0.0) ? 0.0 : (numerator / denominator);
    }
};

// class FuzzyType
// {
//     std::string name;                                      // temperature
//     float minValue;                                        // 0.0
//     float maxValue;                                        // 100.0
//     std::map<std::string, MembershipFunction *> fuzzySets; // cold, warm, hot

// public:
//     FuzzyType(std::string name, float minValue, float maxValue)
//     {
//         this->name = name;
//         this->minValue = minValue;
//         this->maxValue = maxValue;
//     }

//     void addFuzzySet(const std::string &setName, MembershipFunction *membershipFunction)
//     {
//         fuzzySets.emplace(setName, membershipFunction);
//     }

//     std::map<std::string, float> calcFuzzyValues(float input) const
//     {
//         std::map<std::string, float> fuzzyValues;
//         for (const auto &[name, membershipFunction] : fuzzySets)
//         {
//             fuzzyValues[name] = membershipFunction->computeMembership(input);
//         }
//         return fuzzyValues;
//     }
// };

// class FuzzyValues
// {
//     const FuzzyType &fuzzyType;
//     float input;
//     std::map<std::string, float> fuzzyValues;

// public:
//     FuzzyValues(const FuzzyType &fuzzyType, float in) : fuzzyType(fuzzyType), input(in)
//     {
//     }

//     void setInput(float in)
//     {
//         input = in;
//     }

//     void printFuzzyValues() const
//     {
//         for (const auto &[name, value] : fuzzyValues)
//         {
//             std::cout << "Fuzzy value for " << name << ": " << value << std::endl;
//         }
//     }

//     void fuzzify()
//     {
//         fuzzyValues = fuzzyType.calcFuzzyValues(input);
//     }
// };

// class FuzzyRule
// {
//     FuzzyType &inputType;
//     std::string inputSetName;
//     FuzzyType &outputType;
//     std::string outputSetName;

// public:
//     FuzzyRule(FuzzyType &inputType, const std::string &inputSetName, FuzzyType &outputType, const std::string &outputSetName)
//         : inputType(inputType), inputSetName(inputSetName), outputType(outputType), outputSetName(outputSetName);

//         void apply(const FuzzyValues &inputValues, FuzzyValues &outputValues) const
//     {
//         float inputMembership = inputValues.fuzzyType.calcFuzzyValues(inputValues.input)[inputSetName];
//         // For simplicity, we directly set the output membership value to the input membership value.
//         // In a real implementation, you would typically use a more complex inference mechanism.
//         outputValues.setInput(inputMembership);
//     }
// }
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
