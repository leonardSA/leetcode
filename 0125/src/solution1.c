#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/inc/usage.h"

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
    unsigned tail = 0U;
    unsigned head = strlen(s) - 1U;

    while (tail < head)
    {
        const int c_tail = s[tail];
        const int c_head = s[head];
        const unsigned t = isalnum(c_tail) ? 0U : 1U;
        const unsigned h = isalnum(c_head) ? 0U : 1U;
        switch (t + h)
        {
            case 1: (t) ? tail++ : head--; continue;
            case 0: if (tolower(c_tail) != tolower(c_head)) return false; /* case 0 will fall into case 2 */
            case 2: tail++; head--;
        }
    }

    return true;
}
