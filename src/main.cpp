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

    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);
    RAND_bytes(hmac_key, HMAC_KEY_SIZE);

    std::string msg = "Hello world! This is a secret message...";
    std::vector<unsigned char> data(msg.begin(), msg.end());

    // >>>> Tx [encrypted data | iv | sign_hmac] >>>>>>>>
    auto encrypted = encrypt(data, key, iv);
    auto sign = sign_hmac(data, hmac_key, HMAC_KEY_SIZE);

    // <<<< Rx [encrypted data | iv | sign_hmac] <<<<<<<< 
    auto decrypted = decrypt(encrypted, key, iv);
    auto sign_to_verify = sign_hmac(decrypted, hmac_key, HMAC_KEY_SIZE);    // The hmac_key shall be shared between sender and receiver

    if(sign == sign_to_verify)
    {
        std::cout << "Verification ok" << std::endl;
    }
    else
    {
        std::cout << "Verification error" << std::endl;
    }

    std::cout << "Decrypted: "
              << std::string(decrypted.begin(), decrypted.end())
              << std::endl;

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
