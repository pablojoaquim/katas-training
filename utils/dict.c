/*===========================================================================*/
/**
 * @file dict.c
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Dictionaries implementation based in hash tables
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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dict.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

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
/*****************************************************************************
 * Name         hash
 * Description  hash function for strings based in djb2 algorithm, created by
 *              Daniel J. Bernstein.
 *****************************************************************************/
static size_t hash(const char *key, size_t capacity)
{
    size_t h = 5381;
    int c;
    while ((c = *key++))
        h = ((h << 5) + h) + c; // h * 33 + c
    return h % capacity;
}

/*****************************************************************************
 * Name         dict_create
 * Description  Creates a new dictionary with a given capacity and optional value free function.
 *****************************************************************************/
dict *dict_create(size_t capacity, dict_free_fn free_fn)
{
    dict *d = malloc(sizeof(dict));
    d->capacity = capacity;
    d->buckets = calloc(capacity, sizeof(dict_item *));
    d->free_fn = free_fn;
    return d;
}

/*****************************************************************************
 * Name         dict_set
 * Description  Sets or updates the value associated with a key.
 *****************************************************************************/
int dict_set(dict *d, const char *key, void *value)
{
    size_t idx = hash(key, d->capacity);
    dict_item *cur = d->buckets[idx];

    // If the key already exist, overwrite the value
    while (cur)
    {
        if (strcmp(cur->key, key) == 0)
        {
            if (d->free_fn && cur->value)
                d->free_fn(cur->value);
            cur->value = value;
            return 1;
        }
        cur = cur->next;
    }

    // New item
    dict_item *new_item = malloc(sizeof(dict_item));
    size_t key_len = strlen(key);
    new_item->key = malloc(key_len + 1); // +1 for the null terminator
    memcpy(new_item->key, key, key_len); // copy the key string
    new_item->key[key_len] = '\0';       // add null terminator

    new_item->value = value;
    new_item->next = d->buckets[idx];
    d->buckets[idx] = new_item;
    return 1;
}

/*****************************************************************************
 * Name         dict_get
 * Description  Retrieves the value associated with the specified key.
 *****************************************************************************/
void *dict_get(dict *d, const char *key)
{
    size_t idx = hash(key, d->capacity);
    dict_item *cur = d->buckets[idx];
    while (cur)
    {
        if (strcmp(cur->key, key) == 0)
            return cur->value;
        cur = cur->next;
    }
    return NULL;
}

/*****************************************************************************
 * Name         dict_remove
 * Description  Removes the entry for the given key, calling free_fn if defined.
 *****************************************************************************/
int dict_remove(dict *d, const char *key)
{
    size_t idx = hash(key, d->capacity);
    dict_item *cur = d->buckets[idx];
    dict_item *prev = NULL;

    while (cur)
    {
        if (strcmp(cur->key, key) == 0)
        {
            if (prev)
                prev->next = cur->next;
            else
                d->buckets[idx] = cur->next;
            if (d->free_fn && cur->value)
                d->free_fn(cur->value);
            free(cur->key);
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

/*****************************************************************************
 * Name         dict_free
 * Description  Frees the dictionary and all its contents.
 *****************************************************************************/
void dict_free(dict *d)
{
    for (size_t i = 0; i < d->capacity; i++)
    {
        dict_item *cur = d->buckets[i];
        while (cur)
        {
            dict_item *tmp = cur;
            cur = cur->next;
            if (d->free_fn && tmp->value)
                d->free_fn(tmp->value);
            free(tmp->key);
            free(tmp);
        }
    }
    free(d->buckets);
    free(d);
}

/*****************************************************************************
 * Name         dict_foreach
 * Description  Iterate through all nodes in the dict and call the provided
 *              callback function for each element.
 *****************************************************************************/
void dict_foreach(dict *d, dict_iter_fn fn)
{
    if (!d || !fn)
        return;

    for (size_t i = 0; i < d->capacity; i++)
    {
        dict_item *cur = d->buckets[i];
        while (cur)
        {
            fn(cur->key, cur->value);
            cur = cur->next;
        }
    }
}