#ifndef PARSER_H
#define PARSER_H

/*===========================================================================*/
/**
 * @file parser.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION: API for the Person module
 *
 * @todo Add full description here
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
 * Header Files (Common to C and C++)
 *===========================================================================*/
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
/*===========================================================================*
 * Header Files (C++ only)
 *===========================================================================*/
#include <string>
#endif

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define RET_VALID_FRAME      0
#define RET_FORMAT_ERROR    -1
#define RET_INVALID_CHK     -2
#define RET_INVALID_LENGTH  -3

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Classes (C++ only)
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add C++ class declarations here.
#endif

/*===========================================================================*
 * Exported C Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif
// @todo: Add pure C function prototypes here.

/*****************************************************************************
 * @fn         parse_frame
 * @brief      Parse a frame of this type <SOF><TYPE>|<LEN>|<PAYLOAD>|<CHK><ETX>
 *             <SOF>	 Start of frame, character #
 *             <TYPE>	 Message type ('D' data, 'C' command, 'A' Ack)
 *             <LEN>	 Payload length in bytes (decimal ASCII)
 *             <PAYLOAD> Data (ASCII)
 *             <CHK>	 Payload Checksum in hex (2 chars), i.e. 0x41 ^ 0x42 ^ 0x43 = 0x40 -> "40"
 *             <EOF>	 End of frame, character '\n'
 * @param [in] frame - The input frame
 * @return     0 → Valid frame, -1 → Format Error, -2 → Invalid Checksum, -3 → Invalid Length
 ******************************************************************************/
int parse_frame(const char *frame);

#ifdef __cplusplus
} /* extern "C" */
#endif

 /*===========================================================================*
 * Exported C++ Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add pure C++ function prototypes here.

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* PARSER_H */
