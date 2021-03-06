#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ABS(int a)
{
    if (a >= 0) {
        return a;
    } else {
        return (-1 * a);
    }
}

int max(int a, int b)
{
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int sign(int a)
{
    if (a < 0) {
        return -1;
    } else if (a == 0) {
        return 0;
    } else {
        return 1;
    }
}

int min(int a, int b)
{
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int divs(double a, double b)
{
    double c;
    c = a / b;
    if (b >= 0) {
        return floor(c);
    } else {
        return ceil(c);
    }
}

int mod(int a, int b)
{
    return a - divs(a, b) * b;
}

int main(void)
{
    int i0;
    int j0;
    int l0;
    int k = 0;
    scanf("%d %d %d", &i0, &j0, &l0);
    if (((i0 - 10) * (i0 - 10) + (j0 - 10) * (j0 - 10) <= 100) && ((i0 - 10) * (i0 - 10) + (j0 - 10) * (j0 - 10) > 25)) {
        printf("Yes\n%d %d %d %d\n", i0, j0, l0, k);
        return 0;
    }
    int i = i0;
    int j = j0;
    int l = l0;
    int iLast = i0;
    int jLast = j0;
    int lLast = l0;
    for (; k < 50; ++k) {
        i = max(min(iLast + jLast - lLast - k, iLast - jLast + lLast - k), min(k + iLast - jLast - lLast, k - iLast - jLast + lLast));
        j = jLast + mod(lLast * sign(jLast), 20) + mod(k * sign(iLast), 10);
        l = ABS(iLast - jLast + lLast - k) * sign(iLast) * sign(jLast);
        iLast = i;
        jLast = j;
        lLast = l;
        if (((i - 10) * (i - 10) + (j - 10) * (j - 10) <= 100) && ((i - 10) * (i - 10) + (j - 10) * (j - 10) > 25)) {
            printf("Yes\n%d %d %d %d\n", i, j, l, k + 1);
            return 0;
        }
    }
    printf("No\n%d %d %d %d\n", i, j, l, k);
    return 0;
}