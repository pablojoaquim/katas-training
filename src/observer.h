#ifndef OBSERVER_H
#define OBSERVER_H

/*===========================================================================*/
/**
 * @file observer.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Lightweight implementation of the Observer design pattern in C.
 * This module provides a simple and embedded-friendly Observer/Subject
 * mechanism. A Subject maintains a list of observers (callbacks) that are
 * notified whenever an event occurs. Each observer registers a callback and an
 * a user argument that will be passed back during notifications.
 *
 * Typical usage:
 * @code
 * void on_event(struct Subject *s, void *arg) {
 *     printf("Event received: %s\n", (char*)arg);
 * }
 *
 * int main() {
 *     Observer buffer[4];
 *     Subject subject;
 *
 *     subject_init(&subject, buffer, 4);
 *     subject_register(&subject, on_event, "hello!");
 *
 *     subject_notify(&subject); // triggers callback
 *     return 0;
 * }
 * @endcode
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
#include <stddef.h>

#ifdef __cplusplus
/*===========================================================================*
 * Header Files (C++ only)
 *===========================================================================*/
#endif

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
/* Forward declaration */
struct Subject;

/* Observer callback type */
typedef void (*ObserverCallback)(struct Subject *subject, void *arg);

/* Handle representing an observer subscription */
typedef struct Observer {
    ObserverCallback callback;
    void *user_arg;           /* user data passed back to the observer */
} Observer;

/* ==== SUBJECT API ==== */

typedef struct Subject {
    Observer *observers;
    size_t capacity;
    size_t count;
} Subject;

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
extern "C"
{
#endif
// @todo: Add pure C function prototypes here.

/* Initialize subject */
void subject_init(Subject *s, Observer *buffer, size_t capacity);

/* Subscribe an observer */
int subject_register(Subject *s, ObserverCallback cb, void *user_arg);

/* Unsubscribe an observer */
int subject_unregister(Subject *s, ObserverCallback cb);

/* Notify all observers */
void subject_notify(Subject *s);

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
#endif /* OBSERVER_H */
