---
name: functions-header-format
description: 'Apply and enforce the standard function header comment format for functions in .c, .cpp, and .h files. Use when adding APIs, refactoring logic, or documenting existing functions.'
argument-hint: 'Optional function name or file path'
user-invocable: true
---

# Functions Header Format
Use this skill to document function contracts consistently in C and C++ code.

## When to Use
- You add a new function.
- You change function behavior or signature.
- You are improving readability and maintainability of existing code.

## Header File Format (.h)
Use this block for exported/public API declarations in header files:

```c
/*****************************************************************************
 * @fn         <function_name>
 * @brief      <short behavior-oriented summary>
 * @param[in]  <name>  <meaning>
 * @param[out] <name>  <meaning>
 * @return     <return value meaning>
 ******************************************************************************/
```

## Source File Format (.c/.cpp)
Use this block for non-trivial implementation functions in source files:

```c
/*****************************************************************************
 * Name         <function_name>
 * Description  <implementation-oriented description>
 *              <additional behavior details when needed>
 *****************************************************************************/
```

## Additional Rules
- In `.h` files, prefer `@fn/@brief/@param/@return` for exported function prototypes.
- In `.c/.cpp` files, prefer `Name/Description` for local implementation details.
- Use `[in]`, `[out]`, or `[in,out]` direction tags when using `@param`.
- For void functions, `@return None`.
- For no-parameter functions, omit `@param`.
- Keep `@fn` equal to the exact symbol in the signature.
