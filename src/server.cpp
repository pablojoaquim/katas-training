/*===========================================================================*/
/**
 * @file server.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Parser for an Input frame. Refactored for better maintainability.
 */
/*==========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server.h"
#include "httplib.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*****************************************************************************
 * Name         http_server_example
 * Description  Demonstrate how to set up a simple HTTP server using the httplib library
 * Parameters   None
 * Return       None
 *****************************************************************************/
void http_server_example(void)
{
    httplib::Server svr;

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) 
    {
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen("localhost", 8080);
}
