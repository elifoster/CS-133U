/*
    Name: Eli Foster
    Assignment: Selection Extra Credit Assignment
    Date Written: June 5, 2016
    Course: CS 133U, Spring 2016
    Program: PointerFunctions.c
    Purpose: Practice writing code using pointers. This was mostly written
    off the stub provided in the assignment.
    Sources: C Reference
*/

#include <stdio.h>
#include <stdlib.h>

void swapArgs(int*, int*);
void divideArgs(int*, int*);
double* powerArgs(int*, int*);

int main() {
    int parmA;
    int parmB;
    /* used later to reset */
    int parma;
    int parmb;
    printf("Enter 2 integers ");
    scanf("%d %d", &parmA, &parmB);

    /* Store the original values */
    parma = parmA;
    parmb = parmB;

    /* Part A: Swap the values.  Value in parmA is moved to parmB and vice versa */
    printf("A=%d, B=%d. ", parmA, parmB);
    swapArgs(&parmA, &parmB);

    /* Reset the original values after we print the result */
    parmA = parma;
    parmB = parmb;

    /* Part B: Divide parmA by parmB.  Put the quotient in parmA, remainder in parmB */
    printf("Quotient of %d / %d is ", parmA, parmB);
    divideArgs(&parmA, &parmB);
    printf("%d. ", parmA);

    /* Reset the original values after we print the result */
    parmA = parma;
    parmB = parmb;

    /* Part C: Raise parmA to the power of parmB.  Return pointer to the result */
    printf("%d raised to the %d power is ", parmA, parmB);

    /* READ ABOUT FUNCTIONS RETURNING POINTERS*/
    printf("%.0lf \n", *powerArgs(&parmA, &parmB));

    return 0;
}

void swapArgs(int *a, int *b) {
    int tempA = *a;
    *a = *b;
    *b = tempA;
}

void divideArgs(int *dividend, int *divisor) {
    int divTemp = *dividend;
    *dividend = divTemp / *divisor;
}

double* powerArgs(int *base, int *index) {
    int i;
    double val = (double) *base;
    for (i = 1; i < *index; i++) {
        val *= (double) *base;
    }

    double *ptr = &val;
    return ptr;
}