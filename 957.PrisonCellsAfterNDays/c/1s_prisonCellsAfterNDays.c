#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){
    *returnSize = cellsSize;
    int* outCells = (int*) calloc(cellsSize, sizeof(int));
    if (N == 0) {
        memcpy(outCells, cells, sizeof(int) * cellsSize);
        return outCells;
    } 

    /* binomial coefficient C(6, 2) = 15, N starts at 1 */
    N = (N % 14 == 0) ? 14 : N % 14;
    while (N--) {
        for (int i = 1; i < cellsSize - 1 ; i++) {
            outCells[i] = (cells[i - 1] == cells[i + 1]);
        }
        memcpy(cells, outCells, sizeof(int) * cellsSize);
    }

    return outCells;
}


int main(void) {
    int inCells[8] = {1,0,0,1,0,0,0,1};
    int size = 0;
    int N = 0;
    int* outCells = prisonAfterNDays(inCells, 8, N, &size);
    for (unsigned int i = 0 ; i < size ; i++)
        fprintf(stdout, "%d\t", outCells[i]);
    fprintf(stdout, "\n");
    return 0;
}
