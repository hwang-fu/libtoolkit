#pragma once

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <hwangfu/generic.h>
#include <hwangfu/memory.h>
#include <hwangfu/result.h>
#include <hwangfu/assertion.h>

#define assert_filename(filename)                                               \
        do {                                                                    \
            if (!filename)                                                      \
            {                                                                   \
                panic("Error @%s(): filename is nil.", __FUNCTION__);           \
            }                                                                   \
            if (0 == strlen_safe(filename))                                     \
            {                                                                   \
                panic("Error @%s(): filename is \"\"", __FUNCTION__);           \
            }                                                                   \
        } while (0)

