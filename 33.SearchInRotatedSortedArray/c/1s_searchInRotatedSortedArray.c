#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target);

int recSearch(int* nums, int numsSize, int target, int index);

int main(void) {
    return 0;
}

int search(int* nums, int numsSize, int target){
    if (numsSize == 0)
        return -1;
    return recSearch(nums, numsSize, target, 0);
}

int recSearch(int* nums, int numsSize, int target, int index) {
    if (numsSize == 1)
        return (nums[0] == target) ? index : -1;

    if (nums[numsSize / 2] == target)
        return index + numsSize / 2;

    /* avoid searching the other way if found */
    int i = recSearch(nums, numsSize / 2, target, index);
    if (i != -1) return i;
    
    if (numsSize % 2)
        return recSearch(nums + numsSize / 2 + 1, numsSize / 2, target, index + numsSize / 2 + 1);
    else
        return recSearch(nums + numsSize / 2, numsSize / 2, target, index + numsSize / 2);
}
