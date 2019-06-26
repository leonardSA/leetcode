#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main()
{
    int example[4] = {2, 7, 11, 15};
    int size = 4;
    int target = 9;
    int resultSize = 0;
    int *result = twoSum(example, size, target, &resultSize);
    if (result == NULL)
        fprintf(stdout, "No solution found\n");
    else
        fprintf(stdout, "[%d,%d]\n", result[0], result[1]);
    free(result);
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *result = malloc(2*sizeof(int));

    int found = 0;
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
                found = 1;
            }
            j++;
        }
        i++;
    }

    if (!found)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 2;
    return result;
}
