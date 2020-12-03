#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int n = 1;
    for (unsigned int i = 1 ; i < numsSize ; i++) {
        if (nums[i] != nums[n - 1]) {
            nums[n] = nums[i]; 
            n++;
        }
    }
    return n;
}

int main(void) {
    int tab[3] = {1,1,2};
    int size = removeDuplicates(tab, 3);
    for (unsigned int i = 0 ; i < size ; i++)
        fprintf(stdout, "%d, ", tab[i]);
    return 0;
}
