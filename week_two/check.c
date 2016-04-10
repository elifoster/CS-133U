/*
    Name: Eli Foster
    Assignment: Lab 2.0
    Date Written: April 9, 2016
    Course: CS 133U, Spring 2016
    Program: check.c
    Purpose: This program prints a check mark like in the King textbook, though
             it does so dynamically and functionally.
    Sources: C Reference for stdbool, StackOverflow for whether multiplying
             strings is possible.
*/

#include <stdio.h>
#include <stdbool.h>

bool printStart(int);
void loopPrint(char, int);

int main() {
    int begin;
    int end = -3;
    int last = -(end);
    for (begin = 7; begin > 1; begin--) {
        bool printedStartStar = false;
        if (end != last) {
            printedStartStar = printStart(end);
        }
        int spaces;
        if (printedStartStar) {
            spaces = begin - end - 1;
        } else {
            spaces = begin;
        }
        if (spaces > 0) {
            loopPrint(' ', spaces);
            putchar('*');
        }
        printf("\n");
        end++;
    }
    return 0;
}

/**
 * Prints the "starting" asterisk, or the \ in the check mark.
 * @param start The current start integer. If it is negative, it will not print.
 * @return bool Whether the * was printed.
 */
bool printStart(int start) {
    if (start < 0) {
        return false;
    }
    loopPrint(' ', start);
    putchar('*');
    return true;
}

/**
 * A method that replicates multiplying strings in other languages (str * 2).
 * @param character The character to multiply.
 * @param times The multiplier
 * @return void
 */
void loopPrint(char character, int times) {
    int prints;
    for (prints = 0; prints < times; prints++) {
        putchar(character);
    }
}
