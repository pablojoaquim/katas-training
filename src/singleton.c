/*===========================================================================*/
/**
 * @file singleton.c
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Simple Singleton implementation.
 *
 * This file defines a private static instance and exposes stateless functions
 * to operate on it. The instance is initialized only once, the first time it
 * is accessed. Users do not know the structure layout and cannot create more
 * instances.
 * This is the simplest form of the Singleton pattern and is suitable for
 * single-threaded environments.
 * The usage is as follows:
 * int main(void)
 * {
 *     singleton_set_value(123);
 *     printf("Singleton value = %u\n", singleton_get_value());
 *     singleton_set_value(999);
 *     printf("Singleton value = %u\n", singleton_get_value());
 *     return 0;
 * }
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
/*===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "singleton.h"
#include <string.h>

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/* The internal structure of the singleton is private */
struct singleton
{
    uint32_t value;
};

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/

/* The one and only instance (hidden from the user) */
static struct singleton instance;

/* Flag to guarantee initialization only once */
static int singleton_initialized = 0;

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static void singleton_init(void);

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/**
 * @brief Initializes the singleton the first time it is accessed.
 */
static void singleton_init(void)
{
    memset(&instance, 0, sizeof(instance));
    // additional initialization here if needed
    singleton_initialized = 1;
}

/****************************************************************************
 * Name          singleton_set_value
 * Description   Setter for internal data. Initializes on first use.
 *****************************************************************************/
void singleton_set_value(uint32_t value)
{
    if (!singleton_initialized)
        singleton_init();

    instance.value = value;
}

/****************************************************************************
 * Name          singleton_get_value
 * Description   Getter for internal data. Initializes on first use.
 *****************************************************************************/
uint32_t singleton_get_value(void)
{
    if (!singleton_initialized)
        singleton_init();

    return instance.value;
}
