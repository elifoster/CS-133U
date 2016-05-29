/*
    Name: Eli Foster
    Assignment: Lab 9 Assignment
    Date Written: May 29, 2016
    Course: CS 133U, Spring 2016
    Program: lab9.c
    Purpose: Determine whether a given date is earlier than another.
    Sources: N/A
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

bool earlierThan(Date, Date);
void putDate(Date);

int main() {
    Date d1;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
    Date d2;
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

    // I changed this method to return a bool, because we don't actually
    // properly handle when they are the same date in the stub code anyway.
    // Ideally, we would check < 0, == 0, and > 0, rather than < 0 else.
    if (earlierThan(d1, d2)) {
        putDate(d1);
        printf(" is earlier than ");
        putDate(d2);
    } else {
        putDate(d2);
        printf(" is earlier than ");
        putDate(d1);
    }
    printf("\n");
    return 0;
}

/**
 * Returns whether d1 is earlier than d2.
 */
bool earlierThan(Date d1, Date d2) {
    if (d1.year != d2.year) {
        return d1.year < d2.year;
    }
    if (d1.month != d2.month) {
        return d1.month < d2.month;
    }
    if (d1.day != d2.day) {
        return d2.day < d2.day;
    }
    return false;
}

void putDate(Date date) {
    // There was very little instruction on the date formatting here, so I'm
    // just going with this. I would create a switch to print the English
    // names for the month, but it wasn't determined whether January is 0 or
    // 1 in this particular application.
    // The formatting that this provides is pretty ugly, but given the lack
    // of instruction for the format, there's not a whole lot I want to do
    // about it.
    printf("%d/%d/%d", date.month, date.day, date.year);
}