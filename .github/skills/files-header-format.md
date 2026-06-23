---
name: files-header-format
description: 'Apply and enforce the standard file header comment format for .c, .cpp, and .h files in this repository. Use when creating new files or normalizing inconsistent headers.'
argument-hint: 'Optional file path or module name'
user-invocable: true
---

# Files Header Format
Use this skill to keep file-level headers consistent across C and C++ files.

## When to Use
- You create a new .c, .cpp, or .h file.
- You find inconsistent file headers.
- You want to standardize metadata at the top of source files.

## Standard File Header
Use this repository block at the top of every .c, .cpp, and .h file:

```c
/*===========================================================================*/
/**
 * @file <file_name>
 *
 *------------------------------------------------------------------------------
 * Copyright (c) <year> - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * <short description of file purpose>
 *
 * @section ABBR ABBREVIATIONS:
 *   - <abbr>: <meaning>
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - <doc or n/a>
 *   - Requirements Document(s):
 *     - <doc or n/a>
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <standard or n/a>
 *
 */
/*==========================================================================*/
```

## Rules
- Keep `@file` equal to the real filename.
- Keep DESCRIPTION concise and module-oriented.
- Preserve the exact banner separators and section names.
- Do not leave unresolved placeholders like `@todo` in new files unless intentional.
- Do not include secrets, machine-specific paths, or temporary notes.
