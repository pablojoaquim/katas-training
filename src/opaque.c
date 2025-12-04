/*===========================================================================*/
/**
 * @file opaque.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Opaque pattern is an extension of the object pattern where we make the object
 * data structure fully private and not visible outside of the implementation.
 * As the user don't know anything about the Opaque object to reserve the necessary
 * memory a function is necessary to return that size.
 * The usage is as follows:
 * Create an opaque type on the stack
 *      struct opaque *obj = malloc(opaque_size());
 *      opaque_init(obj);
 *      opaque_set_data(obj, 123);
 *      opaque_deinit(obj);
 *      free(obj); 
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
#include "opaque.h"

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
// actual definition of the struct in private space of the c file
struct opaque
{
    uint32_t data;
};

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
opaque_init * Description  Initalize everything in here.
 *              Is the same as the constructor of an object
 *****************************************************************************/
int opaque_init(struct opaque *self)
{
    memset(self, 0, sizeof(*self));
    // do other initialization
    return 0;
}

/*****************************************************************************
 * Name         opaque_deinit
 * Description  Clean everything in here.
 *              Is the same as the destructor of an object
 *****************************************************************************/
int opaque_deinit(struct opaque *self)
{
    // free any internal resources and return to known state
    self->data = 0;
    return 0;
}

/*****************************************************************************
 * Name         opaque_set_data
 * Description  setter
 *****************************************************************************/
void opaque_set_data(struct opaque *self, uint32_t data)
{
    self->data = data;
}

/*****************************************************************************
 * Name         opaque_get_data
 * Description  getter
 *****************************************************************************/
uint32_t opaque_get_data(struct opaque *self)
{
    return self->data;
}

/*****************************************************************************
 * Name         opaque_size
 * Description  Return the size of the struct
 *****************************************************************************/
size_t opaque_size(void)
{
    return sizeof(struct opaque);
}
