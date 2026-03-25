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

    TrapezoidalMembershipFunction hot = TrapezoidalMembershipFunction(30, 40, 45, 45);
    TriangularMembershipFunction warm = TriangularMembershipFunction(20, 30, 35);
    TriangularMembershipFunction cool = TriangularMembershipFunction(10, 20, 25);
    TrapezoidalMembershipFunction cold = TrapezoidalMembershipFunction(0, 0, 10, 15);

    FuzzyType temperature("temperature", 0, 40);

    temperature.addFuzzySet("cold", &cold);
    temperature.addFuzzySet("cool", &cool);
    temperature.addFuzzySet("warm", &warm);
    temperature.addFuzzySet("hot", &hot);

    FuzzyValues fuzzyTemperature = FuzzyValues(temperature, 0);

    for (float value = 0; value <= 40; value += 2.5)
    {
        fuzzyTemperature.setInput(value);
        fuzzyTemperature.fuzzify();
        std::cout << "Input temperature: " << value << std::endl;
        fuzzyTemperature.printFuzzyValues();
        std::cout << "-----------------------------" << std::endl;
    }

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
