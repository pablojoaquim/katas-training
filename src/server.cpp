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

    // Página principal
    svr.Get("/", [](const httplib::Request &, httplib::Response &res)
            {
        std::string html = R"(
        <html>
        <body style="font-family:sans-serif">
            <h1>Mini Spotify</h1>
            <p>Play song:</p>

            <audio controls>
                <source src="/song" type="audio/mpeg">
            </audio>

        </body>
        </html>
        )";
        res.set_content(html, "text/html"); });

    svr.Get("/song", [](const httplib::Request &, httplib::Response &res)
            {
        std::ifstream file("music/Genesis.mp3", std::ios::binary);

        if (!file) 
        {
            std::cout << "ERROR: song.mp3 not found!" << std::endl;
            res.status = 404;
            return;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        res.set_content(buffer.str(), "audio/mpeg"); });

    std::cout << "Mini Spotify running at http://localhost:8080\n";

    svr.listen("0.0.0.0", 8080);
}

/*****************************************************************************
 * Name         http_client_example
 * Description  Demonstrate how to set up a simple HTTP client using the httplib library
 * Parameters   None
 * Return       None
 *****************************************************************************/
void http_client_example(void)
{
    // HTTP
    httplib::Client http_cli("http://yhirose.github.io");

    // HTTPS
    // httplib::Client https_cli("https://yhirose.github.io");

    if (auto res = http_cli.Get("/hi"))
    {
        res->status;
        res->body;
        std::cout << res->body << std::endl;
    }
    else
    {
        auto err = res.error();
        std::cout << "Error: " << err << std::endl;
    }
}
