/*===========================================================================*/
/**
 * @file katas.cpp
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Develop the code to solve the kata in this file
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
#include <cstdint>
#include <sstream>
#include <vector>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

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
 * Name         highAndLow
 * Description  Extracts "<max> <min>" from a space-separated number string.
 *****************************************************************************/
std::string highAndLow(const std::string &numbers)
{
    std::vector<std::string> words;
    std::string word;
    std::stringstream ss(numbers); // Create a stringstream object from the numbers string
    int num;
    int max = INT32_MIN;
    int min = INT32_MAX;

    // Extract words one by one using the extraction operator (>>)
    // The extraction operator by default uses whitespace as a delimiter.
    while (ss >> word)
    {
        words.push_back(word);
    }

    // Analyze the split words
    for (const std::string &w : words)
    {
        try
        {
            num = std::stoi(w); // Convert the string to an integer
            #ifndef NDEBUG
            std::cout << "Converted integer: " << num << std::endl;
            #endif

            if(num>max)
            {
                max = num;
            }
            if(num<min)
            {
                min = num;
            }
        }
        catch (const std::invalid_argument &e)
        {
            #ifndef NDEBUG
            std::cerr << "Invalid argument: " << e.what() << std::endl;
            #endif
        }
        catch (const std::out_of_range &e)
        {
            #ifndef NDEBUG
            std::cerr << "Out of range: " << e.what() << std::endl;
            #endif
        }
    }

    return std::to_string(max) + " " + std::to_string(min);
}
