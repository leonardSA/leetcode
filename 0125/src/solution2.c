#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/inc/usage.h"

/**
 * @brief True if a palindrome despite non alphanumeric characters.
 *
 * @param s input
 *
 * @return true if is palindrome else false
 */
bool isPalindrome(char * s);


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printUsage(argv[0]); 
        return EXIT_FAILURE;
    }

    if (isPalindrome(argv[1])) printf("true\n");
    else                       printf("false\n");

    return EXIT_SUCCESS;
}


bool isPalindrome(char * s)
{
    for (int tail = 0, head = strlen(s) - 1 ; tail < head ; tail++, head--)
    {
        while ((tail < head) && (!isalnum(s[tail]))) tail++;
        while ((tail < head) && (!isalnum(s[head]))) head--;
        if    (tolower(s[tail]) != tolower(s[head])) return false;
    }
    return true;
}
