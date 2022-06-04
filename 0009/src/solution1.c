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


// it writes the number in to opposite way
// 121 -> 121
// 223 -> 322
bool isPalindrome(int x)
{   
    if (x < 0) return false;

    int _x = x;
    uint64_t xReversed = 0;
    while (_x)
    {
        const int remainder = _x % 10;
        xReversed = (xReversed + remainder) * 10; /* store digit in reverse order */
        _x /= 10;
    }
    xReversed /= 10; /* remove extra 0 */

    return (xReversed == x);
}
