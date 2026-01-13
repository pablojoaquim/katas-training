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

/**
 * Input a priority and message from the keyboard.
 *
 * Really fragile--for demo purposes only.
 */
int user_input(char *buf, size_t bufsize, unsigned int *msg_prio)
{
    printf("Priority and message (e.g. 2 hi): ");
    fflush(stdout);
    fgets(buf, bufsize - 1, stdin);
    buf[bufsize - 1] = '\0';
    char *token = strtok(buf, " \n");
    if (token == NULL)
        return 0;
    *msg_prio = atoi(token); // Get priority
    token = strtok(NULL, "\n");
    int msg_len = strlen(token) + 1;
    memmove(buf, token, msg_len);
    return msg_len;
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

    if (!strcmp(argv[1], "sender"))
    {
        char msg[128];
        mqd_t mqdes = mq_open("/mq_test", O_WRONLY | O_CREAT, 0644);
        for (;;)
        {
            unsigned int msg_prio;
            int msg_len = user_input(msg, sizeof msg, &msg_prio);
            if (msg_len == 0)
                break;
            printf("sending \"%s\" (%d bytes) at priority %u\n", msg, msg_len, msg_prio);
            if (mq_send(mqdes, msg, msg_len, msg_prio) == -1)
            {
                perror("mq_send");
            }
        }
        mq_close(mqdes);
    }
    else
    {
        mqd_t mqdes = mq_open("/mq_test", O_RDONLY);
        char msg[128];
        char msg_len = sizeof msg;
        unsigned int msg_prio;
        ssize_t bytes_received;
        for (;;)
        {
            bytes_received = mq_receive(mqdes, msg, msg_len, &msg_prio);
            if (bytes_received == -1)
            {
                perror("mq_receive");
                return 1;
            }
            printf("received \"%s\" (%zd bytes) at priority %u\n", msg, bytes_received, msg_prio);

            // To finalize the receiver
            if(msg_prio == 0)
                break;
        }
        mq_close(mqdes);
    }

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
