#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "../lib/inc/usage.h"

/**
 * @brief Checks if an integer is a palindrome.
 *
 * Writes number opposite way and compares.
 *
 * @param x 
 *
 * @return true if is a palindrome else false
 */
bool isPalindrome(int x);


int main(int argc, char* argv[])
{
    if (2 != argc)
    {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    int input = (int) strtol(argv[1], NULL, 10);
    if (isPalindrome(input)) printf("true\n");
    else                     printf("false\n");

    return EXIT_SUCCESS;
}

// it writes half the number in to opposite way and cmps
// 22 -> 2 == 2
// 62 -> 6 != 2
bool isPalindrome(int x)
{   
    // exp1: avoid negatives
    // exp2: avoid numbers starting with 0 e.g. 10 that are not 0
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int64_t xReverted = 0;
    while (x > xReverted)
    {
        xReverted = xReverted * 10 + x % 10; 
        x /= 10;
    }

    // xReverted / 10: deal with odd number of digits
    return (x == xReverted || x == xReverted / 10);
}
