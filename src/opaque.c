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
 * This file contains the private definition of the opaque object. The structure 
 * is fully defined here and remains hidden from users of the API, who only see 
 * an incomplete forward declaration in the header. This ensures that:
 *   - The internal representation of the object is completely encapsulated.
 *   - The ABI remains stable even if the internal layout changes.
 *   - Users can only interact with the object through the provided functions.
 * Memory for the opaque object must be allocated by the user. The API enforces
 * a construction/destruction lifecycle similar to object-oriented programming:
 *      struct opaque *obj = malloc(opaque_size());
 *      opaque_init(obj);          // constructor
 *      ... use object ...
 *      opaque_deinit(obj);        // destructor
 *      free(obj);
 * This pattern is often used when it is necessary to provide a clean public 
 * interface while keeping implementation details private. It is ideal for 
 * firmware modules, libraries, and abstractions where hiding internal data 
 * improves maintainability, modularity and reduces coupling.
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
