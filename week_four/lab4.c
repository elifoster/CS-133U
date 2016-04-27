/*
    Name: Eli Foster
    Assignment: Lab 4.0
    Date Written: April 23, 2016
    Course: CS 133U, Spring 2016
    Program: lab4.c
    Purpose: Display understanding of limits and variable initialization.
             Calculate the sum of all digits in an integer, and the product
             of the integer and the sum of the digits.
    Sources: C/C++ Reference, StackOverflow
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int arrayToInteger(int[], int);

int main() {
    // Limits
    int integer = 1;
    long int longInt = 1;
    unsigned unsignedInt = 1;
    float floatingPoint = 1.0;
    double doubleVal = 1.0;
    long double longDouble = 1.0;
    char character = 'a';

    printf("%i\n", INT_MAX);
    printf("%li\n", LONG_MAX);
    printf("%u\n", UINT_MAX);
    printf("%f\n", FLT_MAX);
    printf("%f\n", DBL_MAX);
    printf("%Lf\n", LDBL_MAX);
    printf("%c\n", CHAR_MAX);

    // Expressions Sum
    int vals[5];
    scanf("%1i%1i%1i%1i%1i", &vals[0], &vals[1], &vals[2], &vals[3], &vals[4]);
    int index;
    int sum = 0;
    for (index = 0; index < 5; index++) {
        sum += vals[index];
    }

    int value = arrayToInteger(vals, 5);
    int product = value * sum;
    printf("%i * %i = %i\n", value, sum, product);

    return 0;
}

int arrayToInteger(int ary[], int size) {
    int index;
    int ret = 0;
    for (index = 0; index < size; index++) {
        ret = 10 * ret + ary[index];
    }
    return ret;
}