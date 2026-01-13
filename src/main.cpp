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

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

#define MAX_RETRIES 10

// #ifdef NEED_SEMUN
/* Defined in sys/sem.h as required by POSIX now */
union semun
{
    int val;
    struct semid_ds *buf;
    ushort *array;
};
// #endif

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

/*
** initsem() -- more-than-inspired by W. Richard Stevens' UNIX Network
** Programming 2nd edition, volume 2, lockvsem.c, page 295.
*/
int initsem(key_t key, int nsems) /* key from ftok() */
{
    int i;
    union semun arg;
    struct semid_ds buf;
    struct sembuf sb;
    int semid;
    semid = semget(key, nsems, IPC_CREAT | IPC_EXCL | 0666);
    if (semid >= 0)
    { /* we got it first */
        sb.sem_op = 1;
        sb.sem_flg = 0;
        arg.val = 1;
        printf("press return\n");
        getchar();
        for (sb.sem_num = 0; sb.sem_num < nsems; sb.sem_num++)
        {
            /* do a semop() to "free" the semaphores. */
            /* this sets the sem_otime field, as needed below. */
            if (semop(semid, &sb, 1) == -1)
            {
                int e = errno;
                semctl(semid, 0, IPC_RMID); /* clean up */
                errno = e;
                return -1; /* error, check errno */
            }
        }
    }
    else if (errno == EEXIST)
    { /* someone else got it first */
        int ready = 0;
        semid = semget(key, nsems, 0); /* get the id */
        if (semid < 0)
            return semid; /* error, check errno */
        /* wait for other process to initialize the semaphore: */
        arg.buf = &buf;
        for (i = 0; i < MAX_RETRIES && !ready; i++)
        {
            semctl(semid, nsems - 1, IPC_STAT, arg);
            if (arg.buf->sem_otime != 0)
            {
                ready = 1;
            }
            else
            {
                sleep(1);
            }
        }
        if (!ready)
        {
            errno = ETIME;
            return -1;
        }
    }
    else
    {
        return semid; /* error, check errno */
    }
    return semid;
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

    if (!strcmp(argv[1], "seminit"))
    {
        key_t key;
        int semid;
        struct sembuf sb;
        sb.sem_num = 0;
        sb.sem_op = -1; /* set to allocate resource */
        sb.sem_flg = SEM_UNDO;
        if ((key = 123) == -1)
        {
            perror("ftok");
            exit(1);
        }
        /* grab the semaphore set created by seminit: */
        if ((semid = initsem(key, 1)) == -1)
        {
            perror("initsem");
            exit(1);
        }
        printf("Press return to lock: ");
        getchar();
        printf("Trying to lock...\n");
        if (semop(semid, &sb, 1) == -1)
        {
            perror("semop");
            exit(1);
        }
        printf("Locked.\n");
        printf("Press return to unlock: ");
        getchar();
        sb.sem_op = 1; /* free resource */
        if (semop(semid, &sb, 1) == -1)
        {
            perror("semop");
            exit(1);
        }
        printf("Unlocked\n");
        return 0;
    }
    else
    {
        key_t key;
        int semid;
        union semun arg;
        if ((key = 123) == -1)
        {
            perror("ftok");
            exit(1);
        }
        /* grab the semaphore set created by seminit: */
        if ((semid = semget(key, 1, 0)) == -1)
        {
            perror("semget");
            exit(1);
        }
        /* remove it: */
        if (semctl(semid, 0, IPC_RMID, 0) == -1)
        {
            perror("semctl");
            exit(1);
        }
        return 0;
    }

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
