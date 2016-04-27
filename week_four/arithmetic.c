/*
    Name: Eli Foster
    Assignment: Arithmetic Expressions
    Date Written: April 23, 2016
    Course: CS 133U, Spring 2016
    Program: arithmetic.c
    Purpose: Perform arithmetic expressions on user provided integers and
             floats.
    Sources: StackOverflow, C Reference
*/

#include <stdio.h>
#include <math.h>

int main() {
    unsigned val;
    printf("Enter unsigned short int: ");
    scanf("%i", &val);
    int power = pow(2, val);
    printf("The value of 2 raised to the %i power is %i\n", val, power);

    unsigned radius;
    printf("Enter unsigned short int: ");
    scanf("%i", &radius);
    float circumference = 2 * M_PI * radius;
    float area = M_PI * pow(radius, 2);
    printf("A circle with radius %i has circumference of %.3f and an area of "
           "%.3f\n", radius, circumference, area);

    float x;
    printf("Enter a float value: ");
    scanf("%f", &x);
    printf("The value of 2(%.2f)**3 + 3(%.2f)**2 + 4(%.2f) + 5 = %.1f\n", x, x,
           x, 2 * pow(x, 3) + 3 * pow(x, 2) + 4 * x + 5);

    int first;
    int second;
    printf("Enter two integers: ");
    scanf("%i %i", &first, &second);
    printf("The remainder of %i / %i is %i\n", first, second, first % second);

    return 0;
}