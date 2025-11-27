/*===========================================================================*/
/**
 * @file test_suite.c
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Unit tests
 * 
 * @todo Divide this file content using an abstraction layers concept
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
#include "person.h"
#include "animal.h"
#include "acutest.h"

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

/***************************************************************************//**
* @fn         test_person
* @brief      Several tests
* @param [in] void
* @return     void
******************************************************************************/
void test_person(void) {
    Person p1("Alice", 30);
    Person p2("Bob", 25);

    TEST_CHECK(p1.greet() == 0);
    TEST_CHECK(p2.greet() == 0);
}

/***************************************************************************//**
* @fn         test_animal
* @brief      Several tests
* @param [in] void
* @return     void
******************************************************************************/
void test_animal(void) {
    TEST_CHECK(Dog_Walk() == 0);
}

/***************************************************************************//**
* The tests list
******************************************************************************/
TEST_LIST = {
    { "Testing something basic 1", test_person },
    { "Testing something basic 2", test_animal },
    { NULL, NULL }  // terminador
};
