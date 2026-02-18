#ifndef LOGGER_H
#define LOGGER_H

/*===========================================================================*/
/**
 * @file logger.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION: API for the logger
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
#include <cstring>
#include <vector>
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
enum class LogLevel
{
    Debug,
    Info,
    Warn,
    Error,
    Off
};

/*===========================================================================*
 * Exported Classes (C++ only)
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add C++ class declarations here.

// The Logger is implemented as a Singleton class, this ensures that only one 
// instance of the class exists during the entire lifetime of the program.
class Logger
{
public:
    // Provides global access to the single instance.
    // The instance is created the first time this function is called.
    static Logger& getInstance();

    // Set the current logging level
    void setLevel(LogLevel level);

    // Log something
    void debug(std::string_view msg);
    void info (std::string_view msg);
    void warn (std::string_view msg);
    void error(std::string_view msg);

private:
    // Private constructor prevents direct instantiation.
    Logger();

    // Private destructor prevents deletion through external code.
    ~Logger();

    // Delete copy constructor to prevent copying.
    Logger(const Logger&) = delete;

    // Delete copy assignment operator to prevent assignment.
    Logger& operator=(const Logger&) = delete;

    // Delete move constructor to prevent moving.
    Logger(Logger&&) = delete;

    // Delete move assignment operator to prevent moving.
    Logger& operator=(Logger&&) = delete;

    // Log something
    void log(LogLevel level, std::string_view msg);

    // Store the current logging level
    LogLevel currentLevel {LogLevel::Info};
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
#endif /* LOGGER_H */
