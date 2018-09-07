#ifndef __LOG_H__
#define __LOG_H__

#ifdef __LINUX__

#include <stdio.h>
#define LOG(format, ...) \
    printf("[%s]:" format "\n", __FUNCTION__, ##__VA_ARGS__);
#else
#define LOG(...)
#endif

#endif
