/*===========================================================================*/
/**
 * @file smarthome.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Use case to understand the Factory design pattern
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
#include <cstdint>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <vector>
#include <memory>
#include "factory.h"

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

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

void Light::on()
{
    std::cout << "Light ON\n";
}

void Light::off()
{
    std::cout << "Light OFF\n";
}

std::string Light::name() const
{
    return "Light";
}

void Alarm::on()
{
    std::cout << "Alarm ACTIVATED\n";
}

void Alarm::off()
{
    std::cout << "Alarm OFF\n";
}

std::string Alarm::name() const
{
    return "Alarm";
}

std::unique_ptr<Device> DeviceFactory::create(const std::string& type)
{
    if (type == "light")
        return std::make_unique<Light>();

    if (type == "alarm")
        return std::make_unique<Alarm>();

    return nullptr;
}

