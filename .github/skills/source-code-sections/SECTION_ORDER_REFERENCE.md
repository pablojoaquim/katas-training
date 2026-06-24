# Section Order Reference

This file is the detailed reference for `source-code-sections`.

## 1. File Header Comment Block
- File metadata and traceability.
- Must follow the Section 1 template in `TEMPLATES.md`.
- In `.h` files, keep this section inside the include guard.

## 2. Header Files
- All `#include` directives.
- Keep system headers before project headers.

## 3. Exported Preprocessor #define Constants
- Public constants in `.h` files.
- Keep empty in implementation files.

## 4. Exported Type Declarations
- Public `typedef`, `enum`, `struct`, and aliases in `.h` files.
- Keep empty in implementation files.

## 5. Exported Function Declarations
- Public API declarations in `.h` files.
- Function comments follow `functions-header-format`.

## 6. Local Preprocessor #define Constants
- Internal compile-time constants.
- Avoid leaking to public headers.

## 7. Local Preprocessor #define MACROS
- Internal utility macros.
- Prefer inline/static functions when feasible.

## 8. Local Type Declarations
- Internal-only types used in this file.

## 9. Local Object Declarations
- File-scope declarations such as `static` or `extern` objects.

## 10. Local Variables Definitions
- File-scope variable definitions and initial values.

## 11. Local Function Prototypes
- Forward declarations of local functions.

## 12. Local Inline Function Definitions and Function-Like Macros
- Small inline helpers and complex function-like macros.

## 13. Function Definitions
- Function implementations.
- Keep implementation order readable and cohesive.

## Empty Section Example

```c
/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/
```
