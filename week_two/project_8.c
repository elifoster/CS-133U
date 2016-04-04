/*
 * "Write a program that calculates the remaining balance on a loan after the
 * first, second, and third monthly payments:
 * Enter amount of loan: _20000.00_
 * Enter interest rate: _6.0_
 * Enter monthly payment: _386.66_
 *
 * Balance remaining after first payment: $19713.34
 * Balance remaining after second payment: $19425.25
 * Balance remaining after third payment: $19135.71
 *
 * Display each balance with two digits after the decimal point. Hint: Each
 * month, the balance is decreased by the amount of the payment, but
 * increased by the balance times the monthly interest rate. To find the
 * monthly interest rate, convert the interest rate entered by the user to a
 * percentage and divide it by 12.
 */

#include <stdio.h>

int main() {
    float loan;
    float interestRate;
    float monthlyPayment;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);
    float balance = loan;
    float monthlyInterestRate = ((interestRate / 100) / 12) + 1;

    int payment;
    for (payment = 1; payment < 4; payment++) {
        balance *= monthlyInterestRate;
        balance -= monthlyPayment;

        printf("Balance remaining after payment %d: $%.2f\n", payment, balance);
    }
    return 0;
}