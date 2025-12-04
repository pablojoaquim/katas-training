/*===========================================================================*/
/**
 * @file object.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * The most basic and also perhaps the most useful design pattern in C is the object pattern.
 * The object pattern groups data into a hierarchy of data structures and directs functions to
 * operate on these data structures.
 * The key aspect of the object pattern is that it makes data flow along the code path instead of
 * being referenced externally.
 * This has a tremendous effect on cleanliness of the whole software architecture because it
 * gives the programmer a clear view into what data a function will modify directly.
 *  • Context is passed as parameter: we use self parameter to access all data that belongs
 *    to the object upon which a function operates.
 *  • Data is never accessed globally: any global or singleton data is never accessed directly
 *    but instead is accessed through singleton methods (see singleton pattern for more
 *    information on how this is implemented).
 *  • Functions do not have static data: all data is part of the object being operated on. There
 *    is no static data in object methods. Data is either part of the object.
 *  • Data flows along call path: this is an important feature that ensures we have clear
 *    boundaries between methods that use particular data. This is incredibly useful for multithreaded
 *    environments because it makes data locking very straightforward when needed.
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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

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
// int working_arr[100];

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
 * Name         object_init
 * Description  Initalize everything in here. 
 *              Is the same as the constructor of an object
 *****************************************************************************/
int object_init(struct object *self)
{
    memset(self, 0, sizeof(*self));
    return 0;
}

/*****************************************************************************
 * Name         object_deinit
 * Description  Clean everything in here. 
 *              Is the same as the destructor of an object
 *****************************************************************************/
int object_deinit(struct object *self)
{
    // cleanup
    return 0;
}
