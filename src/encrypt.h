#ifndef ENCRYPT_H
#define ENCRYPT_H

/*===========================================================================*/
/**
 * @file encrypt.h
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
#include <openssl/evp.h>
#include <openssl/rand.h>
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
 * @fn         encrypt
 * @brief      Encrypt a sequence of chars with a key and an IV provided
 * @param [in] plaintext - The message to encrypt
 * @param [in] key
 * @param [in] iv
 * @return     The encrypted cipher
 ******************************************************************************/
std::vector<unsigned char> encrypt(
    const std::vector<unsigned char> &plaintext,
    const unsigned char *key,
    const unsigned char *iv);

/*****************************************************************************
 * Name         decrypt
 * Description  Decrypt a cipher, using the key and IV provided
 * @param [in] plaintext - The ciphertext to decrypt
 * @param [in] key
 * @param [in] iv
 * @return     The original message
 *****************************************************************************/
std::vector<unsigned char> decrypt(
    const std::vector<unsigned char> &ciphertext,
    const unsigned char *key,
    const unsigned char *iv);

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* ENCRYPT_H */
