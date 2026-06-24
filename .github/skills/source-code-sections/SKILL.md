---
name: source-code-sections
description: 'Keep .c/.cpp/.h files organized using one mandatory 13-section layout. Includes the file header template and delegates function documentation format to the specialized skill.'
argument-hint: 'Optional file path or section number'
user-invocable: true
---

# Source Code Sections
Use this skill to enforce one consistent file structure for all C/C++ source files.

## When to Use
- You create a new `.c`, `.cpp`, or `.h` file.
- You refactor an existing file for readability.
- You review code for structural consistency.

## Hard Rules
- All files must contain the same 13 sections in the exact order below.
- Empty sections are still required and must keep their section banner.
- Do not reorder, merge, or skip sections.
- Section 1 uses the embedded file header template in `TEMPLATES.md`.
- `.h` files must use include guards around the full file content.
- Function docs use `functions-header-format`.

## Header Guard Rule (.h Files)
Use this pattern to wrap the entire header file:

```c
#ifndef ENCRYPT_H
#define ENCRYPT_H

/* header content */

#endif /* ENCRYPT_H */
```

Guard naming:
- Use uppercase filename with non-alphanumeric characters replaced by `_`.
- Keep opening and closing guard identifiers identical.
- Place the file header block and all 13 sections inside the guard.

## Section Banner Template
Use this exact banner for every section:

```c
/*===========================================================================*
 * <Section Name>
 *===========================================================================*/
```

## Required Section Order
1. File Header Comment Block
2. Header Files
3. Exported Preprocessor #define Constants
4. Exported Type Declarations
5. Exported Function Declarations
6. Local Preprocessor #define Constants
7. Local Preprocessor #define MACROS
8. Local Type Declarations
9. Local Object Declarations
10. Local Variables Definitions
11. Local Function Prototypes
12. Local Inline Function Definitions and Function-Like Macros
13. Function Definitions

## Include Policy (Section 2)
- Put standard/system headers before project headers.
- In `.h` files, split common includes and C++-only includes with `#ifdef __cplusplus` when needed.
- Keep include lists minimal and stable.

## Maintenance Split
- Detailed section-by-section guidance: `SECTION_ORDER_REFERENCE.md`
- Full `.h` and `.cpp/.c` skeletons (including file header): `TEMPLATES.md`

## Related Skills
- `functions-header-format`: canonical function documentation block.
