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
#include "katas.h"
#include "parser.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/un.h>

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
    std::cout << "=== Start ===" << std::endl;

    if (!strcmp(argv[1], "server"))
    {
        int server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (server_fd < 0)
        {
            perror("socket");
            return 1;
        }

        sockaddr_un addr{};
        addr.sun_family = AF_UNIX;
        std::strcpy(addr.sun_path, SOCK_PATH);

        unlink(SOCK_PATH);

        if (bind(server_fd, (sockaddr *)&addr, sizeof(addr)) < 0)
        {
            perror("bind");
            return 1;
        }

        if (listen(server_fd, 1) < 0)
        {
            perror("listen");
            return 1;
        }

        printf("Server listening on %s\n", SOCK_PATH);

        int client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd < 0)
        {
            perror("accept");
            return 1;
        }

        char buf[128];
        int n = read(client_fd, buf, sizeof(buf));
        if (n > 0)
        {
            write(client_fd, buf, n); // echo
        }

        close(client_fd);
        close(server_fd);
        unlink(SOCK_PATH);
    }
    else
    {
        int fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (fd < 0)
        {
            perror("socket");
            return 1;
        }

        sockaddr_un addr{};
        addr.sun_family = AF_UNIX;
        std::strcpy(addr.sun_path, SOCK_PATH);

        if (connect(fd, (sockaddr *)&addr, sizeof(addr)) < 0)
        {
            perror("connect");
            return 1;
        }

        const char *msg = "hola WSL\n";
        write(fd, msg, strlen(msg));

        char buf[128];
        int n = read(fd, buf, sizeof(buf) - 1);
        if (n > 0)
        {
            buf[n] = '\0';
            printf("echo: %s", buf);
        }

        close(fd);
    }

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
