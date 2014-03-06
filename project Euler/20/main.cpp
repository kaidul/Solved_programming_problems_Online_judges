#include <bits/stdc++.h>

using namespace std;

#define DIGIT_COUNT 256

void multiply(int* digits, int factor) {
    int carry = 0;
    for (int i = 0; i < DIGIT_COUNT; i++) {
        int digit = digits[i];
        digit *= factor;
        digit += carry;
        digits[i] = digit % 10;
        carry = digit / 10;
    }
}

int main(int argc, char** argv) {
    int n = 100;

    int digits[DIGIT_COUNT];
    digits[0] = 1;
    for (int i = 1; i < DIGIT_COUNT; i++) {
        digits[i] = 0;
    }

    for (int i = 2; i < n; i++) {
        multiply(digits, i);
    }

    int digitSum = 0;
    for (int i = 0; i < DIGIT_COUNT; i++) {
        digitSum += digits[i];
    }
    printf("%d\n", digitSum);
    return 0;
}
