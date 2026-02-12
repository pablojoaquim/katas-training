/*===========================================================================*/
/**
 * @file design_patterns.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Training on design patterns
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
#include <cstring>
#include <vector>
#include <iostream>
#include "design_patterns.h"

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
/*****************************************************************************
 * Name         Singleton::Singleton
 * Description  Constructor implementation. This will only be executed once.
 *****************************************************************************/
Singleton::Singleton()
{
    std::cout << "Singleton instance created" << std::endl;
}

/*****************************************************************************
 * Name         Singleton::~Singleton
 * Description  Destructor implementation. It will be automatically called at program termination.
 *****************************************************************************/
Singleton::~Singleton()
{
    std::cout << "Singleton instance destroyed" << std::endl;
}

/*****************************************************************************
 * Name         Singleton::getInstance
 * Description  Static method that returns the single instance.
 *              The static local variable is initialized only once.
 *              Since C++11, this initialization is guaranteed to be thread-safe.
 *****************************************************************************/
Singleton& Singleton::getInstance()
{
    static Singleton instance;  // Created once on first call
    return instance;
}

/*****************************************************************************
 * Name         Singleton::doSomething
 * Description  Example method implementation.
 *****************************************************************************/
void Singleton::doSomething() const
{
    std::cout << "Singleton is doing something" << std::endl;
}
