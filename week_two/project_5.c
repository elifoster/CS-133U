/*
 * "Write a program that asks the user to enter a value for x and then
 * displays the value of the following polynomial: 3x^5+2x^4-5x^3-x^2+7x-6"
 */

#include <stdio.h>

// This function only handles positive powers. But, since it is only used
// with positive powers, it is sufficient.
int intpow(int base, int exponent) {
    int ret = 1;
    int iterator;
    for (iterator = 0; iterator < exponent; iterator++) {
        ret *= base;
    }
    return ret;
}

int main() {
    printf("Please enter your x value: ");
    int x;
    scanf("%d", &x);

    int answer = (3 * intpow(x, 5)) + (2 * intpow(x, 4)) - (5 * intpow(x, 3))
                 - intpow(x, 3) + (7 * x) - 6;
    printf("\nAnswer: %d\n", answer);

    return 0;
}