/*
    Name: Eli Foster
    Assignment: Combinations/Selection
    Date Written: May 2, 2016
    Course: CS 133U, Spring 2016
    Program: combinations.c
    Purpose: Calculate the number of combinations of n taken k at a time.
    Sources: Khan Academy and Statistics Fun for Permutation/Combination info.
*/

#include <stdio.h>

int factorial(int);

int main() {
    int n = 0;
    while (n <= 1 || n >= 10) {
        printf("Enter the number of items in the list (n): ");
        scanf("%i", &n);
        if (n <= 1 || n >= 10) {
            printf("?Invalid input: Number must be between 1 and 10\n");
        }
    }

    int k = 0;
    while (k <= 1 || k >= n) {
        printf("Enter the number of items to choose (k): ");
        scanf("%i", &k);
        if (k <= 1 || k >= n) {
            printf("?Invalid input: Number must be between 1 and %i\n", n);
        }
    }

    int sub = n - k;
    int factorialN = factorial(n);
    int factorialK = factorial(k);
    int factorialSub = factorial(sub);
    int combinations = factorialN / (factorialK * factorialSub);

    printf("Number of combinations: %i\n", combinations);

    return 0;
}

/**
 * Returns the factorial ! of the given number non-negative number.
 */
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int i;
    int factorial = 1;
    for (i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}