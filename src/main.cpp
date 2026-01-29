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
    // interval v[] = {{1, 5}, {10, 20}, {1, 6}, {16, 19}, {5, 11}};
    // interval v[] = {{1,5},{-1,2},{2,10}};

    std::vector<std::string> pieces_position_list{
                "F_Yellow",
                "G_Red",
                "D_Yellow",
                "C_Red",
                "A_Yellow",
                "A_Red",
                "E_Yellow",
                "D_Red",
                "D_Yellow",
                "F_Red",
                "B_Yellow",
                "E_Red",
                "C_Yellow",
                "D_Red",
                "F_Yellow",
                "D_Red",
                "D_Yellow",
                "F_Red",
                "G_Yellow",
                "C_Red",
                "F_Yellow",
                "E_Red",
                "A_Yellow",
                "A_Red",
                "C_Yellow",
                "B_Red",
                "E_Yellow",
                "C_Red",
                "E_Yellow",
                "G_Red",
                "A_Yellow",
                "A_Red",
                "G_Yellow",
                "C_Red",
                "B_Yellow",
                "E_Red",
                "F_Yellow",
                "G_Red",
                "G_Yellow",
                "B_Red",
                "B_Yellow",
                "B_Red"
    };

    std::cout << "=== Start ===" << std::endl;
    std::cout << who_is_winner(pieces_position_list) << std::endl;

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
