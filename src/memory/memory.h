#pragma once

#include <stdlib.h>

#include "generic.h"
#include "assertion.h"

/**
 * XFREE(ptr):
 *      1. Frees the pointer if not NIL.
 *      2. Sets the pointer to NIL after freeing.
 */
#define XFREE(ptr)                                                  \
        do {                                                        \
            if ( (ptr) ) free( ptr );                               \
            ptr = NIL;                                              \
        } while (0)

OWNED void * new_(COPIED u64 bytes);
OWNED void * zeros_(COPIED u64 bytes);
COPIED void * dispose(OWNED void * arg);
