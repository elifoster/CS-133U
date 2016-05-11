/*
    Name: Eli Foster
    Assignment: Lab 5
    Date Written: May 2, 2016
    Course: CS 133U, Spring 2016
    Program: lab5_selection.c
    Purpose: To calculate the sum of the smallest and largest of 4 numbers.
    Sources: Class discussion
*/

#include <stdio.h>

int main() {
    printf("Enter 4 integers\n");
    int n;
    int largest = 0;
    int smallest = 0;
    int i;
    for (i = 0; i < 4; i++) {
        scanf("%i", &n);
        if (largest == 0) {
            largest = n;
        }
        if (smallest == 0) {
            smallest = n;
        }
        if (n > largest) {
            largest = n;
        } else if (n < smallest) {
            smallest = n;
        }
    }

    int sum = largest + smallest;
    printf("Sum of the smallest and largest: %i\n", sum);
}