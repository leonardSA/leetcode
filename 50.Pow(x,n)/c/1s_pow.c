#include <stdio.h>
#include <stdlib.h>

double recPow(double x, long int n);

double myPow(double x, int n) {
    if (x == 1.0 || x == 0.0)
        return x;
    if (x == -1.0)
        return x * (n % 2 ? 1 : -1);
    if (n == 0)
        return 1;

    if (n < 0)
        return (1 / recPow(x, (((long int) n) * -1)));
    return recPow(x, (long int) (n));
}

double recPow(double x, long int n) {
    if (n == 1)
        return x;
    double tmp = recPow(x, n / 2);
    if (n % 2)
        return x * tmp * tmp;
    return tmp * tmp;
}

int main(void) {
    /* double x = 2; */
    /* int n = -2; */
    double x = 2.00000;
    int n = -2147483648;

    fprintf(stdout, "%g^%d = %g\n", x, n, myPow(x, n));

    return 0;
}
