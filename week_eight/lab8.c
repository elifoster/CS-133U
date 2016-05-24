/*
    Name: Eli Foster
    Assignment: Lab 8.0
    Date Written: May 24, 2016
    Course: CS 133U, Spring 2016
    Program: lab8.c
    Purpose: Return the factorial of a value non-recursively.
    Sources: Old Ruby code from my project Euler practices.
*/

#include <stdio.h>

int factorial(int);

int main() {
    int value;
    scanf("%d", &value);
    printf("%i\n", factorial(value));
    return 0;
}

/**
 * Returns the factorial of the value.
 */
int factorial(int val) {
    int ret = 1;
    int i;
    for (i = 1; i <= val; i++) {
        ret *= i;
    }

    return ret;
}