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
    fprintf(stderr, "USAGE: %s VAL INTEGER_ARRAY\n"         \
                    "VAL: 0 <= INTEGER <= 100\n"            \
                    "INTEGER_ARRAY:\n"                      \
                    "-  format:  [INTEGER1, ...INTEGERN]\n" \
                    "-  length:  0 <= length   <= 100\n"    \
                    "-  element: 0 <= INTEGERx <= 50\n"     ,
                    executable);
}


#endif
