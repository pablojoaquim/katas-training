/*===========================================================================*/
/**
 * @file logger.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Training on design patterns. This is a functional example of the usage of a Singleton
 * for the use case of a logger. It's a real world use case, as a logger needs to have
 * only ONE instance!
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
#include "logger.h"

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
/*****************************************************************************
 * Name         stdoutSink
 * Description  Interface implementation of the ILogSink for the stdout
 *              This should be in another file, but to simplify we could leave it
 *              here by now!
 *****************************************************************************/
class stdoutSink : public ILogSink
{
public:
    void write(std::string_view msg) override
    {
        // uart_send(msg.data(), msg.size());
        std::cout << "[LOG] " << msg << "\n";
    }
};

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/
static stdoutSink defaultSink;

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
 * Name         Logger::Singleton
 * Description  Constructor implementation. This will only be executed once.
 *****************************************************************************/
Logger::Logger()
{
    std::cout << "Logger instance created" << std::endl;
    sink = &defaultSink;
}

/*****************************************************************************
 * Name         Logger::~Singleton
 * Description  Destructor implementation. It will be automatically called at program termination.
 *****************************************************************************/
Logger::~Logger()
{
    std::cout << "Logger instance destroyed" << std::endl;
}

/*****************************************************************************
 * Name         Logger::getInstance
 * Description  Static method that returns the single instance.
 *              The static local variable is initialized only once.
 *              Since C++11, this initialization is guaranteed to be thread-safe.
 *****************************************************************************/
Logger &Logger::getInstance()
{
    static Logger instance; // Created once on first call
    return instance;
}

/*****************************************************************************
 * Name         Logger::setLevel
 * Description  Set the debugging level
 *****************************************************************************/
void Logger::setLevel(LogLevel level)
{
    // std::cout << "Logger is doing something" << std::endl;
    this->currentLevel = level;
}

/*****************************************************************************
 * Name         Logger::debug
 * Description  Log something
 *****************************************************************************/
void Logger::debug(std::string_view msg)
{
    log(LogLevel::Debug, msg);
}

/*****************************************************************************
 * Name         Logger::info
 * Description  Log something
 *****************************************************************************/
void Logger::info(std::string_view msg)
{
    log(LogLevel::Info, msg);
}

/*****************************************************************************
 * Name         Logger::warn
 * Description  Log something
 *****************************************************************************/
void Logger::warn(std::string_view msg)
{
    log(LogLevel::Warn, msg);
}

/*****************************************************************************
 * Name         Logger::error
 * Description  Log something
 *****************************************************************************/
void Logger::error(std::string_view msg)
{
    log(LogLevel::Error, msg);
}

/*****************************************************************************
 * Name         Logger::log
 * Description  Log something if the log level is lower than the current log level
 *****************************************************************************/
void Logger::log(LogLevel level, std::string_view msg)
{
    if (level < currentLevel)
        return;

    if (sink)
        sink->write(msg);

    // std::cout << "[LOG] " << msg << "\n";
}

/*****************************************************************************
 * Name         Logger::setSink
 * Description  Set the sink for the logging
 *****************************************************************************/
void Logger::setSink(ILogSink *s)
{
    sink = s;
}

