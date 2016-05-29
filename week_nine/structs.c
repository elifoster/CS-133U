/*
    Name: Eli Foster
    Assignment: Structs Assignment
    Date Written: May 29, 2016
    Course: CS 133U, Spring 2016
    Program: structs.c
    Purpose: Show understanding of structs in C by creating Customer
    structures from user input, and sorting them by state, kinda.
    Sources: StackOverflow for some debugging
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10

typedef struct {
    char firstName[30];
    char lastName[30];
    char street[35];
    char city[20];
    char state[3];
    // Storing a zip code in an integer is strange as it implies mathematics.
    // For future assignments I would recommend using a string instead.
    int zip;
    char phone[15];
    int accountID;
} Customer;

Customer createCustomer();

int main() {
    Customer customers[MAX_CUSTOMERS];
    int currentID;
    for (currentID = 0; currentID < MAX_CUSTOMERS; currentID++) {
        Customer customer = createCustomer(currentID);
        customers[currentID] = customer;
    }
    printf("Enter 2-character state code: ");
    char state[3];
    scanf("%s", state);
    for (currentID = 0; currentID < MAX_CUSTOMERS; currentID++) {
        Customer customer = customers[currentID];
        if (strcmp(customer.state, state) == 0) {
            printf("Data for Customer %d\n", customer.accountID);
            printf("Account: %d\n", customer.accountID);
            printf("Name: %s %s\n", customer.firstName, customer.lastName);
            printf("Addr: %s %s %s %d\n", customer.street, customer.city,
                   customer.state, customer.zip);
            printf("Phone: %s\n", customer.phone);
        }
    }
    return 0;
}

Customer createCustomer(int customerID) {
    printf("Enter Data for Customer %d\n", customerID);
    printf("Enter First Last Phone: ");
    char first[30];
    char last[30];
    char phone[15];
    scanf("%s %s %s", first, last, phone);
    printf("Enter Address (Street City State ZIP): ");
    char street[35];
    char city[20];
    char state[3];
    int zip;
    scanf("%s %s %s %d", street, city, state, &zip);
//    Customer *customer;
//    customer->firstName = first;
//    customer->lastName = last;
//    customer->street = street;
//    customer->city = city;
//    customer->state = state;
//    customer->zip = zip;
//    customer->phone = phone;
//    customer->accountID = customerID;
    Customer customer;
    strcpy(customer.firstName, first);
    strcpy(customer.lastName, last);
    strcpy(customer.phone, phone);
    strcpy(customer.street, street);
    strcpy(customer.city, city);
    strcpy(customer.state, state);
    customer.zip = zip;
    customer.accountID = customerID;
//    struct Customer customer = { first, last, street, city, state, zip, phone,
//                                 customerID };
    return customer;
}