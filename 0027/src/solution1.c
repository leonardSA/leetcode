#include <stdio.h>
#include <stdlib.h>
#include "../../lib/inc/libArgumentArray.h"
#include "../lib/inc/usage.h"


/**
 * @brief Remove element from list.
 *
 * @param nums      list of integers
 * @param numsSize  len of list
 * @param val       value to remove
 *
 * @return new len of list
 */
int removeElement(int* nums, int numsSize, int val);


int main(int argc, char* argv[]) 
{
    if (3 != argc)
    {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    struct ArgumentArray* argArray = ArgumentArray_new(sizeof(int));
    int* nums = ArgumentArray_toIntArray(argArray, argv[2]);
    int numsSize = argArray->size;
    int val = atoi(argv[1]);

    numsSize = removeElement(nums, numsSize, val);

    printf("[ ");
    for (unsigned i = 0 ; i < numsSize ; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("]\n");

    ArgumentArray_free(argArray);

    return EXIT_SUCCESS;
}


int removeElement(int* nums, int numsSize, int val)
{
    unsigned slow = 0U;
    for (unsigned fast = 0U ; fast < numsSize ; fast++) 
    {
        if (nums[fast] != val) 
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}
