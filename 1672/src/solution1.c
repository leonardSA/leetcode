#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../lib/inc/libArgumentMatrix.h"

/**
 * @brief Gets the richest customer's wealth.
 *
 * @param accounts          matrix of accounts where each row is a customer's accounts
 * @param accountsSize      number of row
 * @param accountsColSize   number of cols per row
 *
 * @return wealth of the richest motherfucker
 */
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);


int main(int argc, char* argv[]) 
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }
    struct ArgumentMatrix* argMatrix = ArgumentMatrix_new(sizeof(int));
    int** accounts         = ArgumentMatrix_toIntMatrix(argMatrix, argv[1]);
    int   accountsSize     = ArgumentMatrix_rows(argMatrix);
    int*  accountsColsSize = (int*) ArgumentMatrix_cols(argMatrix);

    printf("%d\n", maximumWealth(accounts, accountsSize, accountsColsSize));

    // for (unsigned i = 0U ; i < accountsSize ; i++)
    // {
    //     printf("[ ");
    //     for (unsigned j = 0U ; j < accountsColsSize[i] ; j++) 
    //     {
    //         printf("%d ", accounts[i][j]);
    //     }
    //     printf("]\n");
    // }

    ArgumentMatrix_free(argMatrix);
    return EXIT_SUCCESS;
}


int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max_wealth = 0U;

    /* for each account */
    for (unsigned int i = 0U ; i < accountsSize ; i++)
    {
        int wealth = 0;
        /* sum the account */
        for (unsigned int j = 0U ; j < accountsColSize[i] ; j++) 
        {
            wealth += accounts[i][j];
        }
        /* and keep the largest */
        if (wealth > max_wealth)
        {
            max_wealth = wealth;
        }
    }

    return max_wealth;
}
