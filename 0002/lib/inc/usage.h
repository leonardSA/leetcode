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
    fprintf(stderr, "USAGE: %s DIGIT_ARRAY DIGIT_ARRAY\n"   \
                    "DIGIT_ARRAY:\n"                        \
                    "-  format:  [INTEGER1, ...INTEGERN]\n" \
                    "-  length:  1 <= length   <= 100\n"    \
                    "-  element: 0 <= INTEGERx <= 9\n",
                    executable);
}


#endif
