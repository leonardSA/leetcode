#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max_wealth = 0;

    for (unsigned int i = 0 ; i < accountsSize ; i++)
    {
        int wealth = 0;

        for (unsigned int j = 0 ; j < accountsColSize[i] ; j++) 
        {
            wealth += accounts[i][j];
        }

        if (wealth > max_wealth)
        {
            max_wealth = wealth;
        }
    }

    return max_wealth;
}

int main(void) {
    return EXIT_SUCCESS;
}
