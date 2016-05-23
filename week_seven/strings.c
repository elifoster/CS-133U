/*
    Name: Eli Foster
    Assignment: String Assignment
    Date Written: May 15, 2016
    Course: CS 133U, Spring 2016
    Program: strings.c
    Purpose: Outputs the length of 2 strings, and combines them together.
    Sources: StackOverflow for getchar() solution.
*/

#include <stdio.h>
#include <string.h>

#define ARBITRARY_MAX 254

int main() {
    char string1[ARBITRARY_MAX];
    printf("Enter string 1: ");
    scanf("%[^\n]s", string1);
    // Consume the additional \n to allow the user to actually enter str 2.
    getchar();

    char string2[ARBITRARY_MAX];
    printf("Enter string 2: ");
    scanf("%[^\n]s", string2);

    int length1 = strlen(string1);
    int length2 = strlen(string2);

    printf("String 1 is %i characters long, and String 2 is %i characters "
           "long\n", length1, length2);

    char newString[ARBITRARY_MAX];
    int strI = 0;
    int i;
    for (i = 0; i < length1 / 2; i++) {
        newString[strI] = string1[i];
        strI++;
    }
    for (i = length2 / 2; i < length2; i++) {
        newString[strI] = string2[i];
        strI++;
    }
    printf("First half of string 1 and Second half of string 2 is: \"%s\"\n",
           newString);
    return 0;
}