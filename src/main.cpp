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

    filesystem_example();
    
    // static StdoutSink sink;
    // Logger::getInstance().setSink(&sink);
    // Logger::getInstance().setLevel(LogLevel::Debug);

    // LOG_INFO("System started");
    // LOG_DEBUG("Value received");
    // LOG_WARN("Speed invalid");

    // auto device = DeviceFactory::create("light");
    // if (device)
    //     device->on();

    // Car car;
    // car.SetModel("Sedan");
    // car.SetModel("Sedan", 2020);
    // car.SetModel("Sedan", 2020, "Red");
    // car.SetSpeed(20);
    // car.SetAccel(1);

    // std::cout << add<int>(5, 10) << std::endl;

    // Box<int> intBox(123);
    // std::cout << "Box value: " << intBox.getValue() << std::endl;

    // Box<std::string> strBox("Hello, World!");
    // std::cout << "Box value: " << strBox.getValue() << std::endl;
    
    // Pair<int, std::string> pair(42, "Answer");
    // std::cout << "Pair: (" << pair.getFirst() << ", " << pair.getSecond() << ")" << std::endl;

    // for (int i = 0; i < 10; ++i)
    // {
    //     car.Periodic1SCalc();
    //     std::cout << "Model: "  << car.GetModel() << std::endl;
    //     std::cout << "Model Year: " << car.GetModelYear() << std::endl;
    //     std::cout << "Color: " << car.GetColor() << std::endl;
    //     std::cout << "Speed: " << car.GetSpeed() << std::endl;
    //     car.GetSound();

    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
