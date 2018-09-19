#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*  Name:   Josh Heyer
    Email:  joshuaray83@gmail.com

    Program generates between 1 and 20 questions randomly and promtps user for
    answers to said questions.
    Program then checks user's answers and gives number of correct answers
    at the end.
*/

int generate_question (int);
int answer_question (int);
void print_response (int, int);
int count = 1;
int right;

int main () {
    
    int diff;
    int range;
    int questions;
    int z;
    int indicator = -1;
    int question_answer;

    do {
        printf ("Enter the number of questions(1-20): ");
        scanf ("%d", &questions);
    } while (questions < 1 || questions > 20);

    do {
        printf ("Enter the difficulty level(1-4): ");
        scanf ("%d", &diff);
    } while (diff < 1 || diff > 4);

    if (diff == 1) {
        range = 10;
    }
    else if (diff == 2) {
        range = 50;
    }
    else if (diff == 3) {
        range = 100;
    }
    else {
        range = 200;
    }

    for (z = 0; z < questions; z++) {
        question_answer = generate_question (range);
        indicator = answer_question (question_answer);
        print_response (indicator, question_answer);
        count++;
        indicator = -1;
    }
    printf ("Your score was %d/%d\n", right, count - 1);

    return 0;
}

/* 
    Function: generate_question

    Function generates question based on number range that is based on
    difficulty level.
*/

int generate_question (int range) {

    int answer;
    int operand1;
    int operand2;
    int operator;
    srand(time(NULL));
    
    if (range == 200) {

        operand1 = ((rand() % range) - 99);
        operand2 = ((rand() % range) - 99);
    }
    else {

        operand1 = (rand() % range) + 1;
        operand2 = (rand() % range) + 1;
    }

    do {
        operator = rand() % 4;
    } while (operator < 0 || operator > 3);

    switch (operator) {

        case 0:
            printf ("Question %d: %d + %d = ", count, operand1, operand2);
            answer = operand1 + operand2;
            break;

        case 1:
            printf ("Question %d: %d - %d = ", count, operand1, operand2);
            answer = operand1 - operand2;
            break;

        case 2:
            printf ("Question %d: %d * %d = ", count, operand1, operand2);
            answer = operand1 * operand2;
            break;

        case 3:
            printf ("Question %d: %d / %d = ", count, operand1, operand2);
            answer = operand1 / operand2;
            break;
        
    }

    return answer;
}

/* 
    Function: answer_question

    Functions takes each question's answer as parameter. Function then compares
    the answer with the user's answer and returns 0 if answer correct and -1
    if answer is incorrect.
*/

int answer_question (int answer) {

    int x = -1;
    int their_guess;
    printf ("\nEnter Answer: ");
    scanf ("%d", &their_guess);

    if (answer == their_guess) {
        
        x = 0;
    }

    return x;
}

/* 
    Function: print_response

    Function prints 3 random answers if the user got question right and 3
    other random answers if they got it wrong.
*/
void print_response (int key, int answer) {

    int y;
    do {
        y = rand() % 3;
    } while (y < 0 || y > 2);

    if (key == 0) {
        
        right++;
        switch (y) {
            
            case 0:
                printf ("Good Work!\n");
                break;
            case 1:
                printf ("You Did It!\n");
                break;
            case 2:
                printf ("Correct!\n");
                break;
        }
    }

    if (key == -1) {

        switch (y) {

            case 0:
                printf ("Your not very good at this...\n");
                printf ("The correct answer is: %d\n", answer);
                break;
            case 1:
                printf ("Booooooo!\n");
                printf ("The correct answer is: %d\n", answer);
                break;
            case 2:
                printf ("Close, but no cigar.\n");
                printf ("The correct answer is: %d\n", answer);
                break;
        }
    }
}
