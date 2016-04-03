/*
 * Name: Eli Foster
 * Assignment: Simple Print Assignment
 * Date Written: April 2, 2016
 * Course: CS133U, Spring 2016
 * Program: introduction_printf.c
 * Purpose: This program prints my answers to the introduction questions.
 * Sources: C/C++ Reference, StackOverflow (15161774).
 */

#include <stdio.h>

int main() {
    char *answers[10];
    answers[0] = "My name is Eli Foster.";
    answers[1] = "I am taking CS 133U to learn the C programming language, "
        "obviously. I am interested in C so that I can contribute to Ruby if "
        "needed, and write native extensions for some of my slower-by-nature "
        "Ruby libraries.";
    answers[2] = "I am confident writing in the Java and Ruby languages, and "
        "unfortunately Perl 5 as well. I have several active projects on "
        "GitHub (@elifoster), and work both ont eams and individually for"
        " projects frequently.";
    answers[3] = "I run Mac OS X Yosemite.";
    answers[4] = "I will be using JetBrains' CLion IDE to write programs for "
        "this class.";
    answers[5] = "Online classes are new to me, and I think I prefer in-person "
        "classes more because I can actually interact with my instructor and "
        "classmates. That \"intimacy\" engages me more.";
    answers[6] = "I like how excited my classmates are about learning C. "
        "That sort of anticipation makes me feel excited to learn the "
        "contents of the class as well, for some reason.";
    answers[7] = "I like to do things efficiently, and functionally. "
        "You will likely see this in the code I submit.";
    answers[8] = "I prefer, when someone is helping me solve a problem in a "
        "project, answers that do not inherently answer the question, but get "
        "me thinking about other aspects, and lead me in the right direction"
        " towards the answer. I typically dislike when people just write "
        "code and send it to me as an answer, as that usually does not "
        "actually provide any greater understanding of the concepts.";
    answers[9] = "I live basically in between Southeast and Cascade, but "
        "I am somewhat  closer to Southeast, so that would be best. I live "
        "very far away from Rock Creek and Sylvania, and it would probably "
        "take me several hours to get to either of them.";

    printf("Program: Test Drive\n");
    printf("Author: Eli Foster\n");

    // Actually one less than the answer number.
    int answerNum;
    int max = sizeof(answers) / sizeof(answers[0]);
    for (answerNum = 0; answerNum < max; answerNum++) {
        printf("%i. %s\n", answerNum + 1, answers[answerNum]);
    }

    return 0;
}