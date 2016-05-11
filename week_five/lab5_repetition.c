/*
    Name: Eli Foster
    Assignment: Lab 5
    Date Written: May 2, 2016
    Course: CS 133U, Spring 2016
    Program: lab5_repetition.c
    Purpose: To calculate the mean of provided non-negative non-zero numbers.
    Sources: Class discussion
*/

#include <stdio.h>

int main() {
    int sum = 0;
    int n = 0;
    int count = 0;

    printf("Enter integers to add, <= 0 to end\n");
    scanf("%i", &n);
    while (n > 0) {
        sum += n;
        count++;
        printf("Enter integers to add, <= 0 to end\n");
        scanf("%i", &n);
    }
    float mean = sum / count;
    printf("Mean of integers: %.3f\n", mean);
    return 0;
}