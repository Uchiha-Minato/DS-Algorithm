#include <stdio.h>

/**
 * 欧几里得算法（辗转相除法求最大公约数）
 * */
int getGCD(int m, int n) {
    int r = m % n;
    while (r != 0) {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}

int main(void) {
    printf("%d\n", getGCD(63, 54));
}
