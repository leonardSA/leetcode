#ifndef _USAGE_H_
#define _USAGE_H_

#include <stdio.h>

/**
 * @brief 
 *
 * @param executable
 */
void printUsage(const char* executable);

void printUsage(const char* executable) {
    fprintf(stderr, "USAGE: %s UINTEGER\n"               \
                    "1 <= UINTEGER <= 2^31 - 1\n"        ,
                    executable);
}


#endif
