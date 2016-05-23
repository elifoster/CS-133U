/*
    Name: Eli Foster
    Assignment: Lab 7.0
    Date Written: May 15, 2016
    Course: CS 133U, Spring 2016
    Program: lab7.c
    Purpose: Outputs the palindrome for the given string.
    Sources: StackOverflow, C Reference
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *strrev(char *str);

int main() {
    // Just an arbitrary length...
    char input[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", input);

    char reverse[100];
    memcpy(&reverse, &input, sizeof(input));
    strrev(reverse);

    bool isPalindrome = true;
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (strcmp(&input[i], &reverse[i]) != 0) {
            isPalindrome = false;
            break;
        }
    }

    printf("The palindrome of your input is: ");
    if (isPalindrome) {
        printf("%s\n", reverse);
    } else {
        printf("%s%s\n", input, reverse);
    }

    return 0;
}

/**
 * Taken directly from the source implementation, since Linux does not have it.
 */
char *strrev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}