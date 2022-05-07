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
    fprintf(stderr, "USAGE: %s TARGET INTEGER_ARRAY\n"          \
                    "TARGET: -10^9 <= INTEGER <= 10^9\n"        \
                    "INTEGER_ARRAY:\n"                          \
                    "-  format:  [INTEGER1, ...INTEGERN]\n"     \
                    "-  length:  1     <= length   <= 10^5\n"   \
                    "-  element: -10^9 <= INTEGERx <= 10^9\n",
                    executable);
}


#endif
