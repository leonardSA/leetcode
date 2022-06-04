#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../lib/inc/libArgumentArray.h"
#include "../lib/inc/usage.h"


/**
 * @brief Return indices of two ints adding up to a target in an array.
 *
 * Given an array of integers, return indices of the two numbers 
 * such that they add up to a specific target.
 *
 * @param nums              array
 * @param numsSize          size of array
 * @param target            sum target
 * @param returnSize        size of returned array
 *
 * @return  array containing indexes of ints adding up to target 
 *          if found else NULL
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize);


int main(int argc, char* argv[]) {
    if (3 > argc)
    {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    struct ArgumentArray* argArray = ArgumentArray_new(sizeof(int));
    int* nums = ArgumentArray_toIntArray(argArray, argv[2]);
    const int target = atoi(argv[1]);
    int resultSize = 0;

    int *result = twoSum(nums, argArray->size, target, &resultSize);
    if (NULL == result) printf("No solution found\n");
    else                printf("[%d,%d]\n", result[0], result[1]);

    free(result);
    ArgumentArray_free(argArray);

    return EXIT_FAILURE;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = malloc(2 * sizeof(int));

    bool found = false;
    int i = 0;
    while (i < numsSize && !found)
    {
        int locked = nums[i];
        int j = 0;
        while (j < numsSize && !found)
        {
            if (i == j)
            {
                j++;
                continue;
            }

            if (locked + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                found = true;
            }
            j++;
        }
        i++;
    }

    if (!found)
    {
        *returnSize = 0;
        free(result);
        return NULL;
    }

    *returnSize = 2;
    return result;
}
