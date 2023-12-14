#include <stdio.h>
#include <math.h>

//十进制转二进制
long decimalToBin(int decimal) {
//    int dec_tmp = decimal;
//    if (decimal < 0) {
//        decimal = abs(decimal);
//    }
    int binary[32];
    int i = 0;
    int result = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (binary[j] == 1) {
            result += (long) powl(10, j);
        }
    }
//    if (dec_tmp < 0)
//        result = ~result + 1;
    return result;
}

//二进制转十进制
int binToDec(long binary) {
    int result = 0;
    int arr[32];
    int i = 0;
    while (binary != 0) {
        arr[i++] = binary % 10;
        binary /= 10;
    }
    for (int j = 0; j < i; j++) {
        if (arr[j] != 0)
            result += (int) pow(2, j);
    }
    return result;
}

int getSum(int a, int b) {

    long a_bin = decimalToBin(a);
    long b_bin = decimalToBin(b);
    printf("a的二进制数：%ld\n", a_bin);
    printf("b的二进制数：%ld\n", b_bin);

    int a_arr[32];
    int b_arr[32];
    int i = 0, j = 0;
    while (a_bin != 0) {
        a_arr[i++] = a_bin % 10;
        a_bin /= 10;
    }
    for (int k = i; k < 32; k++) {
        a_arr[k] = 0;
    }

    while (b_bin != 0) {
        b_arr[j++] = b_bin % 10;
        b_bin /= 10;
    }
    for (int k = j; k < 32; k++) {
        b_arr[k] = 0;
    }


    //实现加法，二进制本位用按位异或，进位 先或再与
    int result[32];
    int carry_bit = 0; //进位
    for (int k = 0; k < (int) fmax(i, j); k++) {
        if (carry_bit != 0) {
            result[k] = (a_arr[k] ^ b_arr[k]) ^ carry_bit;
            carry_bit = (a_arr[k] | b_arr[k]) & carry_bit;
        } else {
            result[k] = a_arr[k] ^ b_arr[k];
            carry_bit = a_arr[k] & b_arr[k];
        }

    }
    if (carry_bit == 1) {
        result[(int) fmax(i, j)] = 1;
    }

    long res = 0;
    for (int k = 0; carry_bit == 1 ? k < (int) fmax(i, j) + 1 : k < (int) fmax(i, j); k++) {
        if (result[k] != 0)
            res += (long) powl(10, k);
    }
    printf("二进制结果：%ld\n", res);
    return binToDec(res);
}

int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    printf("%d", getSum(a, b));
//    printf("%d", binToDec(111));
    return 0;
}