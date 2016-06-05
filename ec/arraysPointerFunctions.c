/*
    Name: Eli Foster
    Assignment: Selection Extra Credit Assignment
    Date Written: June 5, 2016
    Course: CS 133U, Spring 2016
    Program: arraysPointerFunctions.c
    Purpose: Practice writing code to manipulate arrays/pointers.
    Sources: CProgramming
*/
#include <stdio.h>
#include <stdlib.h>
#define N 9

void revArray(int*);
int *revElement(int*);
void evenOdd(int*);

int main() {
    /* Load the array with numbers */
    int a[N];
    int idx;
    int *p = a;
    while (p < a + N) {
//        p++;
        *p++ = a + N - p;
    }

    printf("Original: ");
    p = a;
    while (p < a + N) {
        printf("%2d ", *p++);
    }

    /* Part A: Reverse the array */
    revArray(a);
    printf("\nReversed: ");
    p = a;
    while (p < a + N) {
        printf("%2d ", *p++);
    }
    printf("\n");

    /* Part B: Return elements in reverse order */
    printf("Original: ");
    for (idx = 0; idx < N; idx++) {
        printf("%2d ", *revElement(a));
    }
    printf("\n");

    /* Part C: Put even numbers first, odd numbers last in the array.  Order of
    the elements is not important as long as all evens are before first odd */
    printf("Even:     ");
    evenOdd(a);
    p = a;
    while (p < a + N) {
        printf("%2d ", *p++);
    }
    printf("\n");
    return 0;
}

void revArray(int *arr) {
    int arrTemp[N];
    int i;
    for (i = 0; i < N; i++) {
        arrTemp[i] = arr[i];
    }

    int j = N - 1;
    for (i = 0; i < N; i++) {
        arr[i] = arrTemp[j];
        j--;
    }
}

// Not really sure how it's expected to do this without passing the current
// index.
int currentArrayIndex = N - 1;

int *revElement(int *arr) {
    int val = arr[currentArrayIndex];
    currentArrayIndex--;
    return &val;
}

void evenOdd(int *arr) {
    int temp[N];
    int i;
    for (i = 0; i < N; i++) {
        temp[i] = arr[i];
    }

    int even = 0;
    int odd = N - 1;
    for (i = 0; i < N; i++) {
        int me = temp[i];
        if (me % 2 == 0) {
            arr[even] = me;
            even++;
        } else {
            arr[odd] = me;
            odd--;
        }
    }
}