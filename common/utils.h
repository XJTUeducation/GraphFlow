#ifndef __UTILS_H__
#define __UTILS_H__

#include "common/log.h"

#define DIE(message) \
do { \
    LOG(message); \
    exit(0); \
} while (0)

#define ASSERT_PTR(ptr, message) \
do { \
    if (!ptr) \
        DIE(message); \
} while (0)

#endif
