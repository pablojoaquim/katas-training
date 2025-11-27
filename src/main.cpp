/*===========================================================================*/
/**
 * @file main.cpp
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   The rgb function is incomplete. Complete it so that passing in RGB decimal values 
 *   will result in a hexadecimal representation being returned. Valid decimal values 
 *   for RGB are 0 - 255. Any values that fall out of that range must be rounded to the
 *   closest valid value.
 *   Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.
 *   Examples (input --> output):
 *   255, 255, 255 --> "FFFFFF"
 *   255, 255, 300 --> "FFFFFF"
 *   0, 0, 0       --> "000000"
 *   148, 0, 211   --> "9400D3"
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

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

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
 * @fn         to_printable
 * @brief      Helper function
 * @param [in] val
 * @return     The value of val as a printable char
 ******************************************************************************/
std::uint8_t to_printable(uint8_t val)
{
    if (val < 0)
    {
        return 0;
    }
    else if (val >= 0x0A)
    {
        return val + 'A' - 0x0A;
    }
    else
    {
        return val + '0';
    }
}

/*****************************************************************************
 * @fn         rgb_to_hex
 * @brief      Passing in RGB decimal values will result in a hexadecimal representation
 * @param [in] r
 * @param [in] g
 * @param [in] b
 * @return     The max between a and b
 ******************************************************************************/
std::string rgb_to_hex(int r, int g, int b)
{
    if (r < 0)
        r = 0;
    if (r > 255)
        r = 255;
    if (g < 0)
        g = 0;
    if (g > 255)
        g = 255;
    if (b < 0)
        b = 0;
    if (b > 255)
        b = 255;

    std::string aux;

    aux.append(1, to_printable((r >> 4 & 0x0F)));
    aux.append(1, to_printable((r >> 0 & 0x0F)));
    aux.append(1, to_printable((g >> 4 & 0x0F)));
    aux.append(1, to_printable((g >> 0 & 0x0F)));
    aux.append(1, to_printable((b >> 4 & 0x0F)));
    aux.append(1, to_printable((b >> 0 & 0x0F)));

    return aux;
}

/*****************************************************************************
 * @fn         main
 * @brief      The main entry point
 * @param [in] void
 * @return     0 -success, -1 -Error
 ******************************************************************************/
int main(int argc, char *argv[])
{
    std::cout << "=== The result is: " << rgb_to_hex(-20, 275, 3) << " ===" << std::endl;

    return 0;
}
