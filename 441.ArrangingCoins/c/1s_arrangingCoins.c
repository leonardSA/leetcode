#include <stdio.h>
#include <stdlib.h>

int arrangeCoins(int n) {
    unsigned int i = 1;
    unsigned int k = 0;

    while (i <= n) {
        ++k;
        i = i + k + 1;
    }

    return k;
}

int main(int argc, char** argv) {
    int n = atoi(argv[1]);
    int res = arrangeCoins(n);
    fprintf(stdout, "%d\n", res);
    return 0;
}
