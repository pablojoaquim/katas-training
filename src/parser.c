/*===========================================================================*/
/**
 * @file parser.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Parser for an Input frame. It's developed based in a FSM.
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
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parser.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define MAX_FRAME_LENGTH 500
#define MAX_FIELD_TYPE_LENGTH 1
#define MAX_FIELD_LEN_LENGTH 2
#define MAX_FIELD_PAYLOAD_LENGTH 100
#define MAX_FIELD_CHK_LENGTH 2

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef enum cs_parser_Tag
{
    CS_PARSER_WAIT_SOF,
    CS_PARSER_PROCESS_TYPE,
    CS_PARSER_PROCESS_LEN,
    CS_PARSER_PROCESS_PAYLOAD,
    CS_PARSER_PROCESS_CHK,
    CS_PARSER_WAIT_EOF
} cs_parser_t;

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/
cs_parser_t cs_parser;
char frame_type[MAX_FIELD_TYPE_LENGTH];
char frame_length[MAX_FIELD_LEN_LENGTH];
char frame_payload[MAX_FIELD_PAYLOAD_LENGTH];
char frame_chk[MAX_FIELD_CHK_LENGTH];

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

void printArr(int code, size_t len, char *arr)
{
    printf("-- %d --- ", code);
    for (size_t i = 0; i < len; ++i)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

/*****************************************************************************
 * Name         parse_frame
 * Description  Parse a frame of this type <STX><TYPE>|<LEN>|<PAYLOAD>|<CHK><ETX>
 *              <SOF>	 Start of frame, character #
 *              <TYPE>	 Message type ('D' data, 'C' command, 'A' Ack)
 *              <LEN>	 Payload length in bytes (decimal ASCII)
 *              <PAYLOAD> Data (ASCII)
 *              <CHK>	 Payload Checksum in hex (2 chars), i.e. 0x41 ^ 0x42 ^ 0x43 = 0x40 -> "40"
 *              <EOF>	 End of frame, character '\n'
 * Return       0 → Valid frame, -1 → Format Error, -2 → Invalid Checksum, -3 → Invalid Length
 *****************************************************************************/
int parse_frame(const char *frame)
{
    /* Control variables initialization */
    int idx = 0;
    cs_parser = CS_PARSER_WAIT_SOF;
    int inputCnt = 0;
    int payloadLength = 0;
    int checksum = 0;
    int frame_chk_value = 0;
    // char frame_type[1];
    // char frame_length[2];
    // char frame_payload[100];
    // char frame_chk[2];

    /* The parser state machine */
    while ((*(frame+idx)!='\n') && (idx < MAX_FRAME_LENGTH))
    {
        switch (cs_parser)
        {
        case CS_PARSER_WAIT_SOF:
            printf("CS_PARSER_WAIT_SOF\n");
            if ('#' == *(frame + idx))
            {
                cs_parser = CS_PARSER_PROCESS_TYPE;
                inputCnt = 0;
            }
            break;

        case CS_PARSER_PROCESS_TYPE:
            printf("CS_PARSER_PROCESS_TYPE\n");
            if (inputCnt < MAX_FIELD_TYPE_LENGTH)
            {
                frame_type[inputCnt++] = *(frame + idx);
            }
            else if ('|' == *(frame + idx))
            {
                if (('D' == frame_type[0]) || ('C' == frame_type[0]) || ('A' == frame_type[0]))
                {
                    cs_parser = CS_PARSER_PROCESS_LEN;
                    inputCnt = 0;
                }
                else
                {
                    return RET_FORMAT_ERROR;
                }
            }
            else
            {
                return RET_FORMAT_ERROR;
            }
            break;

        case CS_PARSER_PROCESS_LEN:
            printf("CS_PARSER_PROCESS_LEN\n");
            if ('|' == *(frame + idx))
            {
                if (inputCnt == 2)
                    payloadLength = (frame_length[0] - '0') * 10 + (frame_length[1] - '0');
                else if (inputCnt == 1)
                    payloadLength = (frame_length[0] - '0');
                else
                    return RET_INVALID_LENGTH;

                if (payloadLength < MAX_FIELD_PAYLOAD_LENGTH)
                {
                    cs_parser = CS_PARSER_PROCESS_PAYLOAD;
                    inputCnt = 0;
                }
                else
                {
                    return RET_INVALID_LENGTH;
                }
            }
            else if (inputCnt < MAX_FIELD_LEN_LENGTH)
            {
                frame_length[inputCnt++] = *(frame + idx);
            }
            break;

        case CS_PARSER_PROCESS_PAYLOAD:
            printf("CS_PARSER_PROCESS_PAYLOAD\n");
            if (inputCnt < MAX_FIELD_PAYLOAD_LENGTH)
            {
                if ('|' == *(frame + idx))
                {
                    if (inputCnt != payloadLength)
                    {
                        return RET_INVALID_LENGTH;
                    }
                    else
                    {
                        frame_payload[inputCnt] = '\0';
                        cs_parser = CS_PARSER_PROCESS_CHK;
                        inputCnt = 0;
                    }
                }
                else
                {
                    frame_payload[inputCnt++] = *(frame + idx);
                    checksum ^= *(frame + idx);
                }
            }
            else if ('|' == *(frame + idx))
            {
                frame_payload[inputCnt] = '\0';
                cs_parser = CS_PARSER_PROCESS_CHK;
                inputCnt = 0;
            }
            else
            {
                return RET_INVALID_LENGTH;
            }
            break;

        case CS_PARSER_PROCESS_CHK:
            printf("CS_PARSER_PROCESS_CHK\n");
            
            if (inputCnt < MAX_FIELD_CHK_LENGTH)
            {
                frame_chk[inputCnt++] = *(frame + idx);
            }
            if(inputCnt >= MAX_FIELD_CHK_LENGTH)
            {
                if (frame_chk[0] >= 0 && frame_chk[0] <= '9')
                {
                    frame_chk_value = (frame_chk[0] - '0') * 16;
                }
                else if (frame_chk[0] >= 'A' && frame_chk[0] <= 'F')
                {
                    frame_chk_value = ((frame_chk[0] - 'A') + 10) * 16;
                }
                if (frame_chk[1] >= 0 && frame_chk[1] <= '9')
                {
                    frame_chk_value += (frame_chk[1] - '0');
                }
                else if (frame_chk[1] >= 'A' && frame_chk[1] <= 'F')
                {
                    frame_chk_value += (frame_chk[1] - 'A') + 10;
                }
                if (frame_chk_value != checksum)
                {
                    return RET_INVALID_CHK;
                }
            }
            break;

        case CS_PARSER_WAIT_EOF:
            break;
        }
        idx++;
    }

    printf("Type: %c\n", frame_type[0]);
    printf("Length: %d\n", payloadLength);
    printf("Payload: %s\n", frame_payload);
    printf("Checksum: %d\n", frame_chk_value);
    printf("\n");
    return RET_VALID_FRAME;
    // printArr(0, 5, (char *)frame);
    return RET_FORMAT_ERROR;
}
