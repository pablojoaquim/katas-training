#ifndef DESIGN_PATTERNS_H
#define DESIGN_PATTERNS_H

/*===========================================================================*/
/**
 * @file design_patterns.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION: API for the encrypt module
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

/*===========================================================================*
 * Exported Classes (C++ only)
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add C++ class declarations here.

// The Singleton class ensures that only one instance of the class
// exists during the entire lifetime of the program.
class Singleton
{
public:
    // Provides global access to the single instance.
    // The instance is created the first time this function is called.
    static Singleton& getInstance();

    // Example public method
    void doSomething() const;

private:
    // Private constructor prevents direct instantiation.
    Singleton();

    // Private destructor prevents deletion through external code.
    ~Singleton();

    // Delete copy constructor to prevent copying.
    Singleton(const Singleton&) = delete;

    // Delete copy assignment operator to prevent assignment.
    Singleton& operator=(const Singleton&) = delete;

    // Delete move constructor to prevent moving.
    Singleton(Singleton&&) = delete;

    // Delete move assignment operator to prevent moving.
    Singleton& operator=(Singleton&&) = delete;
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

/*****************************************************************************
 * Name         sign_hmac
 * Description  Generate a signature for a message using a key.
 *              The idea is to have a simmetric key between sender and receiver
 *              to verify the authenticity of the origin of the message
 * @param [in] data - The data to calc the mac
 * @param [in] key - The key to calc the mac
 * @param [in] key_len
 * @return     The calculated mac using HMAC
 *****************************************************************************/

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* DESIGN_PATTERNS_H */
