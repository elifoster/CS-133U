/*
    Name: Eli Foster
    Assignment: Trip Planner Functions Assignment
    Date Written: May 24, 2016
    Course: CS 133U, Spring 2016
    Program: tripPlanner.c
    Purpose: Plans your roadtrips!
    Sources: N/A
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define BREAK_LENGTH 60

void outputWelcomeMessage();

bool handleFuelData();
float getNeededGallons(int, int);
float getApproximateCost(float, float);

void prompt(char[]);
void outputBreak();
void printEquals(int);
void outputHeader(char[]);

int main() {
    outputWelcomeMessage();
    outputBreak();
    do {} while (handleFuelData());
    printf("Thank you, please drive safely and have a nice trip!\n");

    return 0;
}

/**
 * Prints the Trip Planner welcome message.
 */
void outputWelcomeMessage() {
    printf("Welcome to the Trip Planner!\n");
    printf("So you are ready to take a trip? Let me help you plan for\n");
    printf("your fuel costs and required stops to fill up your tank.\n");
    outputBreak();
    printf("Please provide answers to the prompts below and I will\n");
    printf("display a summary for you when I have computed the results.\n");
}

/**
 * Prompts the user for fuel data, and performs the according calculations
 * for said data.
 * @return Whether we performed any calculations. False when the user inputs
 * 0 to quit the program.
 */
bool handleFuelData() {
    prompt("Please input your car's average miles per gallon (enter 0 to "
               "quit)");
    int mpg;
    scanf("%d", &mpg);
    if (mpg == 0) {
        return false;
    }

    printf("Please tell me the range of fuel costs you expect to pay per "
               "gallon\n");
    prompt("The lowest per gallon cost of fuel is");
    float low;
    scanf("%f", &low);
    prompt("The highest per gallon cost of fuel is");
    float high;
    scanf("%f", &high);
    prompt("Please tell me how many miles you plan to travel");
    int miles;
    scanf("%d", &miles);

    float neededGallons = getNeededGallons(mpg, miles);
    float lowCost = getApproximateCost(low, neededGallons);
    float highCost = getApproximateCost(high, neededGallons);

    outputHeader("Trip Summary");
    printf("You will need to purchase %.2f gallons of fuel.\n", neededGallons);
    printf("The approximate cost of fuel for your trip is between $%.2f and "
               "$%.2f.\n", lowCost, highCost);
    outputHeader("End Trip Summary");

    return true;
}

/**
 * @param mpg Average miles per gallon for the car
 * @param miles Miles planned to drive
 * @return float The gallons of fuel needed for the trip.
 */
float getNeededGallons(int mpg, int miles) {
    return (float) miles / (float) mpg;
}

/**
 * @param perGallonCost The cost of a gallon of gasoline expected.
 * @param neededGallons The amount of gallons needed.
 * @return The approximate cost of gasoline for the trip.
 */
float getApproximateCost(float perGallonCost, float neededGallons) {
    return perGallonCost * neededGallons;
}

/**
 * Helper method for our prompting format.
 */
void prompt(char str[]) {
    printf("%s >> ", str);
}

/**
 * Output a standard break with a newline at the end.
 */
void outputBreak() {
    printEquals(BREAK_LENGTH);
    printf("\n");
}

/**
 * Output a given number of = characters. This does not print a newline.
 * @param len The number of = to print.
 */
void printEquals(int len) {
    int i;
    for (i = 0; i < len; i++) {
        putchar('=');
    }
}

/**
 * Outputs a header with a length identical to the breaks.
 * @param str The content of the header.
 */
void outputHeader(char str[]) {
    // Subtract an additional 2 for spacing.
    int length = BREAK_LENGTH - 2 - strlen(str);
    printEquals(length / 2);
    printf(" %s ", str);
    printEquals(length / 2);
    printf("\n");
}