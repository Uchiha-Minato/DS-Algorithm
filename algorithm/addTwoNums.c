#include <stdio.h>

/**
 * 两数之和，用位运算实现
 * */
int getSum(int a, int b) {

    while (b != 0) {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    printf("%d", getSum(a, b));
    return 0;
}
