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
    fprintf(stderr, "USAGE: %s NUMBER\n"                  \
                    "NUMBER: -2^31 <= INTEGER <= 2^31-1\n", 
                    executable);
}


#endif
