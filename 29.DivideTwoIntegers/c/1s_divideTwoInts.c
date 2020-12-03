#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

unsigned int absint(int x) {
    if (x < 0) {
        if (x == INT_MIN)
            return ((unsigned int) INT_MAX) + 1;
        else
            return (unsigned int) (~x + 1);
    }
    return x;
}

int divide(int dividend, int divisor) {
    if (divisor == 0)
        return INT_MAX;

    unsigned int q = 0;
    unsigned int b = absint(dividend);
    unsigned int a = absint(divisor);

    for (int i = 31 ; i >= 0 ; i--) {
        if ((b >> i) >= a) {
            q = (q << 1) | 0x01;
            b = b - (a << i);
        } else {
            q = q << 1;
        }
    }

    if ((dividend < 0) ^ (divisor < 0))
        return (~q + 1);
    return (q == INT_MIN) ? INT_MAX : q;
}

int main(int argc, char** argv) {
    fprintf(stdout, "%s / %s = %d\n", 
            argv[1], argv[2], 
            divide(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
