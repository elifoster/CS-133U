/*
    Name: Eli Foster
    Assignment: Arrays Assignment
    Date Written: May 10, 2016
    Course: CS 133U, Spring 2016
    Program: arrays.c
    Purpose: Counts character occurences in a string.
    Sources: StackOverflow, C Reference, G Praveen Kumar's blog
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ASCII_LENGTH 128

float getPercent(float, float);
bool in(char, char[], int);

int main() {
    printf("Enter string 1: ");
    char string[128];
    scanf("%[^\n]s", string);
    int length = strlen(string);

    int ary[ASCII_LENGTH] = { 0 };

    int charIndex;
    for (charIndex = 0; charIndex < length; charIndex++) {
        ary[(unsigned char) string[charIndex]]++;
    }

    printf("\nFREQUENCY TABLE\n");
    printf("---------------\n");
    printf("Char Count %% of Total\n");
    printf("---- ----- ----------\n");
    printf("ALL  %i   %.2f%%\n", length, getPercent(length, length));

    char done[ASCII_LENGTH];
    for (charIndex = 0; charIndex < length; charIndex++) {
        unsigned char c = string[charIndex];
        if (!in(c, done, ASCII_LENGTH)) {
            int count = ary[c];
            printf("\"%c\"  %i  %.2f%%\n", c, count, getPercent(count, length));
            done[charIndex] = c;
        }
    }

    return 0;
}

/**
 * Returns the percentage part is of whole.
 */
float getPercent(float part, float whole) {
    return (part / whole) * 100.0F;
}

/**
 * Gets whether needle is in haystack, assuming they are characters.
 */
bool in(char needle, char haystack[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (needle == haystack[i]) {
            return true;
        }
    }
    return false;
}