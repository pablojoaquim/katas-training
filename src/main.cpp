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
#include <cstring>
#include <cstdint>
#include <vector>
#include <thread>
#include <chrono>
#include <unordered_set>
#include "katas.h"
#include "parser.h"
#include "encrypt.h"
#include "singleton.h"
#include "logger.h"
#include "logger_sink_stdout.h"
#include "factory.h"
#include "server.h"
#include "filters.h"
#include "fuzzy_logic.h"

#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"

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
    (void)argc;
    (void)argv;

    std::cout << "=== Start ===" << std::endl;

    std::string input = "apples, pears # and bananas\ngrapes\nbananas !apples";
    std::unordered_set<char> markers = {'#', '!'};
    std::cout << stripComments(input, markers) << std::endl;

    // // =========================
    // // 1. VARIABLES
    // // =========================
    // LinguisticVariable temperature("temperature", 0, 40);
    // LinguisticVariable fanSpeed("fan", 0, 100);

    // // =========================
    // // 2. FUZZY SETS
    // // =========================

    // // Temperature sets
    // temperature.addFuzzySet("cold", new TriangularMembershipFunction(0, 0, 20));
    // temperature.addFuzzySet("warm", new TriangularMembershipFunction(10, 20, 30));
    // temperature.addFuzzySet("hot", new TriangularMembershipFunction(20, 40, 40));

    // // Fan speed sets
    // fanSpeed.addFuzzySet("low", new TriangularMembershipFunction(0, 0, 50));
    // fanSpeed.addFuzzySet("medium", new TriangularMembershipFunction(25, 50, 75));
    // fanSpeed.addFuzzySet("high", new TriangularMembershipFunction(50, 100, 100));

    // // =========================
    // // 3. REGLAS
    // // =========================
    // InferenceEngine engine;

    // engine.addRule(FuzzyRule(
    //     {{&temperature, "cold"}},
    //     {&fanSpeed, "low"}));

    // engine.addRule(FuzzyRule(
    //     {{&temperature, "warm"}},
    //     {&fanSpeed, "medium"}));

    // engine.addRule(FuzzyRule(
    //     {{&temperature, "hot"}},
    //     {&fanSpeed, "high"}));

    // // =========================
    // // 4. INPUT CRISP
    // // =========================
    // double inputTemp = 25.0;

    // // =========================
    // // 5. FUZZIFY
    // // =========================
    // std::map<LinguisticVariableName, std::map<FuzzySetName, double>> inputs;
    // inputs["temperature"] = temperature.fuzzify(inputTemp);

    // // Debug
    // std::cout << "Fuzzified temperature:\n";
    // for (const auto &[set, val] : inputs["temperature"])
    //     std::cout << "  " << set << " = " << val << "\n";

    // // =========================
    // // 6. INFERENCIA
    // // =========================
    // auto outputs = engine.infer(inputs);

    // std::cout << "\nFuzzy output (fan):\n";
    // for (const auto &[set, val] : outputs["fan"])
    //     std::cout << "  " << set << " = " << val << "\n";

    // // =========================
    // // 7. DEFUZZIFY
    // // =========================
    // Defuzzifier defuzz;

    // std::vector<FuzzySet> fanSets = {
    //     FuzzySet("low", new TriangularMembershipFunction(0, 0, 50)),
    //     FuzzySet("medium", new TriangularMembershipFunction(25, 50, 75)),
    //     FuzzySet("high", new TriangularMembershipFunction(50, 100, 100))};

    // // double result = defuzz.defuzzify(outputs["fan"], fanSets);

    // double result = defuzz.defuzzify(
    //     outputs["fan"],
    //     fanSpeed.fuzzySets,
    //     0.0,  // min
    //     100.0 // max
    // );

    // std::cout << "\nFinal fan speed: " << result << "\n";

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
