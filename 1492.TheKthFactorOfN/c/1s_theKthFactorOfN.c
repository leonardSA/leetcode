#include <stdio.h>
#include <stdlib.h>

int kthFactor(int n, int k) {
    for (unsigned int i = 1 ; i <= n ; i++)
    {
        if (0 == (n % i))
        {
            --k;
        }

        if (0 == k)
        {
            return i;
        }
    }
    return -1;
}


int main(void) {
    int n = 7;
    int k = 2;
    int result = 0;
    
    result = kthFactor(n, k);
    printf("k=%d, n=%d => result=%d\n", k, n, result);

    return EXIT_SUCCESS;
}
