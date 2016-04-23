/*
 * Name: Eli Foster
 * Assignment: Data Exercise Assignment and formatted IO
 * Date Written: April 12, 2016
 * Course: CS133U, Spring 2016
 * Program: dataExercise.c
 * Purpose: This program declares, reads, and prints variables using scanf
 *          and printf.
 * Sources: C Reference, StackOverflow
 */

#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
    // (1)
    char a = 'a';
    putchar(a);
    printf("\n%d\n", a);

    // (2)
    short max = SHRT_MAX;
    printf("%d\n", max);

    // (3)
    double infinity = HUGE_VAL;
    printf("%f\n", infinity);

    // (4, 5)
    printf("Enter char int char float: ");
    char one;
    int two;
    char three;
    float four;
    scanf("%c %i %c %f", &one, &two, &three, &four);
    getchar();
    printf("You entered: '%c' %i '%c' %.3f\n", one, two, three, four);

    // (6, 7)
    printf("Enter char float int char: ");
    char five;
    float six;
    int seven;
    char eight;
    scanf("%c %f %i %c", &five, &six, &seven, &eight);
    getchar();
    printf("You entered: '%c' %.3f %i '%c'\n", five, six, seven, eight);

    // (8, 9)
    printf("Enter an integer value: ");
    int nine;
    scanf("%i", &nine);
    getchar();
    printf("You entered: %015i\n", nine);

    // (10, 11)
    printf("Enter a float value: ");
    float ten;
    scanf("%f", &ten);
    getchar();
    printf("You entered: %15.2f\n", ten);

    return 0;
}