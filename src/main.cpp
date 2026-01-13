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
#include <cstdint>
#include "katas.h"
#include "parser.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

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
volatile sig_atomic_t got_usr1;
volatile sig_atomic_t got_int;

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

void sigusr1_handler(int sig)
{
    got_usr1 = 1;
    /* using a char[] so that sizeof will work */
    const char msg[] = "SIGUSR1 signal received!\n";
    write(0, msg, sizeof(msg));
}

void sigint_handler(int sig)
{
    got_int = 1;
    /* using a char[] so that sizeof will work */
    const char msg[] = "SIGINT signal received!\n";
    write(0, msg, sizeof(msg));
}

/*****************************************************************************
 * @fn         main
 * @brief      The main entry point
 * @param [in] void
 * @return     0 -success, -1 -Error
 *****************************************************************************/
int main(int argc, char *argv[])
{
    int pfds[2];
    char buf[30];

    std::cout << "=== Start ===" << std::endl;

    if (pipe(pfds) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid_t pid;
    switch (pid = fork())
    {
    case -1:
        perror("fork"); /* something went wrong */
        exit(1);        /* parent exits */
    case 0:
        printf(" CHILD: This is the child process!\n");
        printf(" CHILD: My PID is %d\n", getpid());
        printf(" CHILD: My parent's PID is %d\n", getppid());
        printf(" CHILD: writing to the pipe\n");
        write(pfds[1], "test", 5);
        printf(" CHILD: Terminating!\n");
        exit(0);
    default:
        printf("PARENT: This is the parent process!\n");
        printf("PARENT: My PID is %d\n", getpid());
        printf("PARENT: My child's PID is %d\n", pid);
        read(pfds[0], buf, 5);
        printf("PARENT: read \"%s\"\n", buf);
        wait(NULL);
        printf("PARENT: Terminating!\n");
    }

    // const int arr1[] = {1, 2,3,4,5,6,6,7,8,9};
    // const int arr2[] = {1};

    // size_t length;
    // int *actual = camelCaseBreaker(arr1, ARRAY_LENGTH(arr1), arr2, ARRAY_LENGTH(arr2), &length);

    // printf("{ ");
    // for (size_t i = 0; i < length; i++)
    //     printf("%d%s", actual[i], (i == length - 1) ? "" : ", ");
    // printf(" }");

    // free(actual);

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
