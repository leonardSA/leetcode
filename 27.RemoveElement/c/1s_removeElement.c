#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    for (int j = 0 ; j < numsSize ; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}


int main(void) {
    int nums[1] = {1};
    int numsSize = 1;
    int val = 1;
    numsSize = removeElement(nums, numsSize, val);
    for (unsigned int i = 0 ; i < numsSize ; i++)
        fprintf(stdout, "%d ", nums[i]);
    return 0;
}
