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

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

#define SOCK_PATH "/tmp/echo_socket"

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
constexpr int KEY_SIZE = 32;        // AES-256
constexpr int IV_SIZE = 16;         // CBC
constexpr int HMAC_KEY_SIZE = 32;   // HMAC

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

    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    unsigned char hmac_key[HMAC_KEY_SIZE];

    std::cout << "=== Start ===" << std::endl;

    // static StdoutSink sink;
    // Logger::getInstance().setSink(&sink);
    // Logger::getInstance().setLevel(LogLevel::Debug);

    // LOG_INFO("System started");
    // LOG_DEBUG("Value received");
    // LOG_WARN("Speed invalid");

    // auto device = DeviceFactory::create("light");
    // if (device)
    //     device->on();

    Car car;
    car.SetSpeed(20);
    car.SetAccel(1);

    for (int i = 0; i < 10; ++i)
    {
        car.Periodic1SCalc();
        std::cout << "Speed: " << car.GetSpeed() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
