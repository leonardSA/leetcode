#include <stdio.h>
#include <stdlib.h>
#include "../lib/inc/usage.h"


/**
 * @brief Gets number of rows that can be made in a staircase with n coins.
 *
 * Staircase meaning the in k rows the i'th row has exactly i coins.
 * Follows suite:
 *  i0 = 1
 *  k0 = 0
 *  in+1 = in + kn+1 + 1
 *  kn+1 = kn + 1
 *
 * @param n number of coins
 *
 * @return number of rows
 */
int arrangeCoins(int n);


int main(int argc, char* argv[]) 
{
    if (2 != argc)
    {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    int n   = atoi(argv[1]);
    int res = arrangeCoins(n);
    printf("%d\n", res);

    return EXIT_SUCCESS;
}


int arrangeCoins(int n) 
{
    unsigned int i = 1U;
    unsigned int k = 0U;

    while (i <= n) { i += (++k) + 1U; }

    return (int) k;
}
