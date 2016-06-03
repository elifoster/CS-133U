/*
    Name: Eli Foster
    Assignment: Selection Extra Credit Assignment
    Date Written: June 2, 2016
    Course: CS 133U, Spring 2016
    Program: selection.c
    Purpose: Evaluate a given arithmetic/relational/logical expression. I did
    so in a way that was probably way more verbose than would actually be
    done in a production API or application, but I figured that the
    additional experience working with C structs (and enums for a little
    while, before that was abandoned) was beneficial. This is especially the
    case since this assignment is an extra credit assignment. This program
    also includes a large amount of utility methods for type conversion,
    reading, and writing.
    Sources: StackOverflow for some debugging
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_OPERATORS 5
#define ARITHMETIC_ID 0
#define RELATIONAL_ID 1
#define LOGICAL_ID 2
#define INVALID_ID 3

typedef struct {
    char validChars[MAX_OPERATORS];
    int id;
} OperatorType;

OperatorType ARITHMETIC = { { '+', '-', '*', '/', '%' }, ARITHMETIC_ID };
OperatorType RELATIONAL = { { '<', '>' }, RELATIONAL_ID };
OperatorType LOGICAL = { { '&', '|', '!' }, LOGICAL_ID };
OperatorType INVALID = {{}, INVALID_ID};

typedef struct {
    OperatorType type;
    char operatorCharacter;
} Operator;

OperatorType getCorrectType(char);
Operator buildOperator(char);
int performArithmetic(int, char, int);
bool performRelation(int, char, int);
bool performLogical(int, char, int);
bool includes(char, char*);
int fromBool(bool);
int toBool(int);
void printBool(bool);
bool areTypesEqual(OperatorType, OperatorType);

int main() {
    int a;
    int b;
    int c;
    int d;

    char x;
    char y;
    char z;

    // (a x b) y (c z d)
    char format[] = "(%i %c %i) %c (%i %c %i)";

    printf("Enter an expression: ");
    scanf(format, &a, &x, &b, &y, &c, &z, &d);

    Operator operatorX = buildOperator(x);
    Operator operatorY = buildOperator(y);
    Operator operatorZ = buildOperator(z);

    OperatorType expressionOperatorType;

    // TODO: Make the Result: output more dynamic with a function.
    if (!areTypesEqual(operatorX.type, operatorY.type) ||
        !areTypesEqual(operatorY.type, operatorZ.type) ||
        !areTypesEqual(operatorX.type, operatorZ.type)) {
        printf("Result: ");
        printf(format, a, x, b, y, c, z, d);
        printf(" is not a valid expression for this program\n");
        return 1;
    } else {
        expressionOperatorType = operatorX.type;
    }

    printf("Result: ");
    printf(format, a, x, b, y, c, z, d);
    printf(" = ");
    // This would be so much easier with functional programming...
    if (areTypesEqual(expressionOperatorType, ARITHMETIC)) {
        int result = performArithmetic(
            performArithmetic(a, operatorX.operatorCharacter, b),
            operatorY.operatorCharacter,
            performArithmetic(c, operatorZ.operatorCharacter, d)
        );
        printf("%i", result);
    } else if (areTypesEqual(expressionOperatorType, RELATIONAL)) {
        bool result = performRelation(
            fromBool(
                performRelation(a, operatorX.operatorCharacter, b)
            ),
            operatorY.operatorCharacter,
            fromBool(
                performRelation(c, operatorZ.operatorCharacter, d)
            )
        );
        printBool(result);
    } else if (areTypesEqual(expressionOperatorType, LOGICAL)) {
        bool result = performLogical(
            fromBool(
                performLogical(a, operatorX.operatorCharacter, b)
            ),
            operatorY.operatorCharacter,
            fromBool(
                performLogical(c, operatorZ.operatorCharacter, d)
            )
        );
        printBool(result);
    } else if (areTypesEqual(expressionOperatorType, INVALID)) {
        printf("invalid\n");
        return 1;
    }
    printf("\n");

    return 0;
}

int performArithmetic(int a, char operatorChar, int b) {
    switch (operatorChar) {
        case '+' : {
            return a + b;
        }
        case '-': {
            return a - b;
        }
        case '*': {
            return a * b;
        }
        case '/': {
            return a / b;
        }
        case '%': {
            return a % b;
        }
    }
    return 0;
}

bool performRelation(int a, char operatorChar, int b) {
    switch (operatorChar) {
        case '<': {
            return a < b;
        }
        case '>': {
            return a > b;
        }
    }
    return false;
}

bool performLogical(int a, char operatorChar, int b) {
    switch (operatorChar) {
        case '&': {
            return a && b;
        }
        case '|': {
            return a || b;
        }
        case '!': {
            return !(a && b);
        }
    }
    return false;
}

Operator buildOperator(char operatorChar) {
    OperatorType type = getCorrectType(operatorChar);
    if (areTypesEqual(type, INVALID)) {
        printf("ERROR: Invalid operator character.");
        exit(1);
    }

    Operator op;
    op.operatorCharacter = operatorChar;
    op.type = type;
    return op;
}

OperatorType getCorrectType(char operatorChar) {
    if (includes(operatorChar, ARITHMETIC.validChars)) {
        return ARITHMETIC;
    }
    if (includes(operatorChar, RELATIONAL.validChars)) {
        return RELATIONAL;
    }
    if (includes(operatorChar, LOGICAL.validChars)) {
        return LOGICAL;
    }
    return INVALID;
}

bool includes(char val, char *arr) {
    int i;
    for (i = 0; i < sizeof(arr); i++) {
        if (arr[i] == val) {
            return true;
        }
    }
    return false;
}

int fromBool(bool val) {
    return val ? 1 : 0;
}

int toBool(int val) {
    return val == 1;
}

void printBool(bool val) {
    if (val) {
        printf("true");
    } else {
        printf("false");
    }
}

bool areTypesEqual(OperatorType a, OperatorType b) {
    return a.id == b.id;
}