/*
    Name: Eli Foster
    Assignment: Lab 3.0
    Date Written: April 17, 2016
    Course: CS 133U, Spring 2016
    Program: lab.c
    Purpose: This program takes either a phone number (+1(xxx)-xxx-xxxx) and
             outputs the sum of all its digits, or takes 4 lines of input
             (float, char, 4 digit integer, char) and outputs them on a
             single line.
    Sources: StackOverflow
*/

#include <stdio.h>

int main() {
    float first;
    char second;
    int third;
    char fourth;
    int phoneNumber[10];
    if (scanf("+1(%1i%1i%1i)-%1i%1i%1i-%1i%1i%1i%1i", &phoneNumber[0],
                     &phoneNumber[1], &phoneNumber[2], &phoneNumber[3],
                     &phoneNumber[4], &phoneNumber[5], &phoneNumber[6],
                     &phoneNumber[7], &phoneNumber[8], &phoneNumber[9]) == 10) {
        int index;
        int sum = 0;
        for (index = 0; index < 10; index++) {
            sum += phoneNumber[index];
        }
        printf("%i\n", sum);
    } else if (scanf("%f\n%c\n%4i\n%c", &first, &second, &third, &fourth) ==
        4) {
        printf("%4.2f %c %i %c\n", first, second, third, fourth);
    } else {
        return 1;
    }
    return 0;
}