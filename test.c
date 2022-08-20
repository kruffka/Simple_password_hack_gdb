#include <stdio.h>

long sum_func(long a, long b, long c, long d, long e, long f, long g, long h, long i) {

    long sum = 0;

    sum = a + b + c + d + e + f + g + h + i;

    return sum;
}

int main() {

    long a = 1;
    long b = 2;
    long c = 3;
    long d = 4;
    long e = 5;
    long f = 6;
    long g = 7;
    long h = 8;
    long i = 9;
    long j;

    printf("Input pass..\n");
    j = sum_func(a, b, c, d, e, f, g, h, i);
    printf("j = %ld\n", j);

    return 0;
}