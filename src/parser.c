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
#include "parser.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define MAX_FRAME_LENGTH 500
#define MAX_FIELD_PAYLOAD_LENGTH 99
#define CHECKSUM_FIELD_LENGTH 2

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef enum
{
    STATE_WAIT_SOF,
    STATE_PROCESS_TYPE,
    STATE_PROCESS_LEN,
    STATE_PROCESS_PAYLOAD,
    STATE_PROCESS_CHK,
    STATE_COMPLETE
} parser_state_t;

typedef struct
{
    parser_state_t state;
    size_t field_index;
    char type;
    int payload_length;
    char payload[MAX_FIELD_PAYLOAD_LENGTH + 1];
    int computed_checksum;
    char checksum_chars[CHECKSUM_FIELD_LENGTH];
} parser_context_t;

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static void init_parser_context(parser_context_t *ctx);
static int hex_char_to_int(char c);
static int hex_string_to_int(const char *hex_str, size_t len);
static bool is_valid_frame_type(char type);
static int parse_length_field(const char *len_str, size_t len);

static int process_sof(parser_context_t *ctx, char c);
static int process_type(parser_context_t *ctx, char c);
static int process_length(parser_context_t *ctx, char c);
static int process_payload(parser_context_t *ctx, char c);
static int process_checksum(parser_context_t *ctx, char c);

/*===========================================================================*
 * Helper Function Definitions
 *===========================================================================*/

/*****************************************************************************
 * Name         init_parser_context
 * Description  Initialization function
 *****************************************************************************/
static void init_parser_context(parser_context_t *ctx)
{
    ctx->state = STATE_WAIT_SOF;
    ctx->field_index = 0;
    ctx->type = '\0';
    ctx->payload_length = 0;
    ctx->computed_checksum = 0;
    memset(ctx->payload, 0, sizeof(ctx->payload));
    memset(ctx->checksum_chars, 0, sizeof(ctx->checksum_chars));
}

/*****************************************************************************
 * Name         hex_char_to_int
 * Description  Helper function
 *****************************************************************************/
static int hex_char_to_int(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F')
    {
        return (c - 'A') + 10;
    }
    if (c >= 'a' && c <= 'f')
    {
        return (c - 'a') + 10;
    }
    return -1;
}

/*****************************************************************************
 * Name         hex_string_to_int
 * Description  Helper function
 *****************************************************************************/
static int hex_string_to_int(const char *hex_str, size_t len)
{
    if (len != 2)
    {
        return -1;
    }

    int high = hex_char_to_int(hex_str[0]);
    int low = hex_char_to_int(hex_str[1]);

    if (high < 0 || low < 0)
    {
        return -1;
    }

    return (high << 4) | low;
}

/*****************************************************************************
 * Name         is_valid_frame_type
 * Description  Frame type verification
 *****************************************************************************/
static bool is_valid_frame_type(char type)
{
    return (type == 'D' || type == 'C' || type == 'A');
}

/*****************************************************************************
 * Name         parse_length_field
 * Description  Length from Str to int
 *****************************************************************************/
static int parse_length_field(const char *len_str, size_t len)
{
    if (len == 0 || len > 2)
    {
        return -1;
    }

    int result = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (len_str[i] < '0' || len_str[i] > '9')
        {
            return -1;
        }
        result = result * 10 + (len_str[i] - '0');
    }

    if (result > MAX_FIELD_PAYLOAD_LENGTH)
    {
        return -1;
    }

    return result;
}

/*===========================================================================*
 * State Processing Functions
 *===========================================================================*/

static int process_sof(parser_context_t *ctx, char c)
{
    if (c == '#')
    {
        ctx->state = STATE_PROCESS_TYPE;
        ctx->field_index = 0;
        return RET_VALID_FRAME; // Continue processing
    }
    return RET_FORMAT_ERROR;
}

static int process_type(parser_context_t *ctx, char c)
{
    if (ctx->field_index == 0)
    {
        ctx->type = c;
        ctx->field_index++;
        return RET_VALID_FRAME; // Continue
    }

    if (c == '|')
    {
        if (!is_valid_frame_type(ctx->type))
        {
            return RET_FORMAT_ERROR;
        }
        ctx->state = STATE_PROCESS_LEN;
        ctx->field_index = 0;
        return RET_VALID_FRAME; // Continue
    }

    return RET_FORMAT_ERROR;
}

static int process_length(parser_context_t *ctx, char c)
{
    if (c == '|')
    {
        char len_buffer[3];
        memcpy(len_buffer, ctx->checksum_chars, ctx->field_index);

        ctx->payload_length = parse_length_field(len_buffer, ctx->field_index);
        if (ctx->payload_length < 0)
        {
            return RET_INVALID_LENGTH;
        }

        ctx->state = STATE_PROCESS_PAYLOAD;
        ctx->field_index = 0;
        return RET_VALID_FRAME; // Continue
    }

    if (ctx->field_index >= 2)
    {
        return RET_FORMAT_ERROR;
    }

    if (c < '0' || c > '9')
    {
        return RET_FORMAT_ERROR;
    }

    ctx->checksum_chars[ctx->field_index++] = c;
    return RET_VALID_FRAME; // Continue
}

static int process_payload(parser_context_t *ctx, char c)
{
    if (c == '|')
    {
        if ((int)ctx->field_index != ctx->payload_length)
        {
            return RET_INVALID_LENGTH;
        }

        ctx->payload[ctx->field_index] = '\0';
        ctx->state = STATE_PROCESS_CHK;
        ctx->field_index = 0;
        return RET_VALID_FRAME; // Continue
    }

    if (ctx->field_index >= MAX_FIELD_PAYLOAD_LENGTH)
    {
        return RET_INVALID_LENGTH;
    }

    ctx->payload[ctx->field_index++] = c;
    ctx->computed_checksum ^= c;
    return RET_VALID_FRAME; // Continue
}

static int process_checksum(parser_context_t *ctx, char c)
{
    if (ctx->field_index < CHECKSUM_FIELD_LENGTH)
    {
        ctx->checksum_chars[ctx->field_index++] = c;

        if (ctx->field_index == CHECKSUM_FIELD_LENGTH)
        {
            int received_checksum = hex_string_to_int(ctx->checksum_chars, CHECKSUM_FIELD_LENGTH);
            if (received_checksum < 0)
            {
                return RET_FORMAT_ERROR;
            }

            if (received_checksum != ctx->computed_checksum)
            {
                return RET_INVALID_CHK;
            }

            ctx->state = STATE_COMPLETE;
        }
        return RET_VALID_FRAME; // Continue
    }

    return RET_FORMAT_ERROR;
}

/*===========================================================================*
 * Main Parser Function
 *===========================================================================*/

/*****************************************************************************
 * Name         parse_frame
 * Description  Parse a frame of this type: #<TYPE>|<LEN>|<PAYLOAD>|<CHK>\n
 *              <SOF>     Start of frame, character '#'
 *              <TYPE>    Message type ('D' data, 'C' command, 'A' Ack)
 *              <LEN>     Payload length in bytes (decimal ASCII, 1-2 digits)
 *              <PAYLOAD> Data (ASCII)
 *              <CHK>     Payload Checksum in hex (2 chars), XOR of payload bytes
 *              <EOF>     End of frame, character '\n'
 * Parameters   frame - null-terminated string containing the frame
 * Return       0  → Valid frame
 *             -1  → Format Error
 *             -2  → Invalid Checksum
 *             -3  → Invalid Length
 *****************************************************************************/
int parse_frame(const char *frame)
{
    if (frame == NULL)
    {
        return RET_FORMAT_ERROR;
    }

    parser_context_t ctx;
    init_parser_context(&ctx);

    size_t idx = 0;
    int result = RET_VALID_FRAME;

    while (frame[idx] != '\n' && frame[idx] != '\0' && idx < MAX_FRAME_LENGTH)
    {
        char current_char = frame[idx];

        switch (ctx.state)
        {
        case STATE_WAIT_SOF:
            result = process_sof(&ctx, current_char);
            break;

        case STATE_PROCESS_TYPE:
            result = process_type(&ctx, current_char);
            break;

        case STATE_PROCESS_LEN:
            result = process_length(&ctx, current_char);
            break;

        case STATE_PROCESS_PAYLOAD:
            result = process_payload(&ctx, current_char);
            break;

        case STATE_PROCESS_CHK:
            result = process_checksum(&ctx, current_char);
            break;

        case STATE_COMPLETE:
            // Frame already complete, unexpected character
            return RET_FORMAT_ERROR;
        }

        if (result != RET_VALID_FRAME)
        {
            return result;
        }

        idx++;
    }

    // Verify we reached the end properly
    if (frame[idx] != '\n')
    {
        return RET_FORMAT_ERROR;
    }

    if (ctx.state != STATE_COMPLETE)
    {
        return RET_FORMAT_ERROR;
    }

#ifndef NDEBUG
    printf("Type: %c\n", ctx.type);
    printf("Length: %d\n", ctx.payload_length);
    printf("Payload: %s\n", ctx.payload);
    printf("Checksum: %02X\n", ctx.computed_checksum);
    printf("\n");
#endif

    return RET_VALID_FRAME;
}