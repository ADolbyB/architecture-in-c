/**
 * Joel Brigida
 * CDA-4102: Computer Architecture
 * This is a simpler Parser example that uses an FSM (Finite State Machine)
 * to determine if user entered input is valid.
 * Written in C Language
 * 
 * This model can be modified to accomodate different needs.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    STATE_START,
    STATE_DIGIT,
    STATE_LETTER,
    STATE_ERROR
} State;

void parseInput(const char* input)
{
    State currentState = STATE_START;
    char currentChar;
    int i = 0;

    while ((currentChar = input[i]) != '\0')
    {
        switch (currentState)
        {
            case STATE_START:
                if (isdigit(currentChar))
                {
                    currentState = STATE_DIGIT;
                }
                else if (isalpha(currentChar))
                {
                    currentState = STATE_LETTER;
                }
                else
                {
                    currentState = STATE_ERROR;
                }
                break;
            case STATE_DIGIT:
                if (!isdigit(currentChar))
                {
                    currentState = STATE_ERROR;
                }
                break;
            case STATE_LETTER:
                if (!isalpha(currentChar))
                {
                    currentState = STATE_ERROR;
                }
                break;
            case STATE_ERROR:
                break;
        }

        if (currentState == STATE_ERROR)
        {
            break;
        }
        i++;
    }

    switch (currentState)                                       // Check the final state
    {
        case STATE_DIGIT:
            printf("Input is a number.\n");
            break;
        case STATE_LETTER:
            printf("Input is a word.\n");
            break;
        case STATE_ERROR:
            printf("Error: Invalid input.\n");
            break;
    }
}

int main()
{
    char userInput[100];
    printf("Enter an input: ");

    if (fgets(userInput, sizeof(userInput), stdin) != NULL)     // Use fgets to safely read user input and handle newline character
    {
        size_t len = strlen(userInput);                         // Remove the newline character from the input (if present)
        if (len > 0 && userInput[len - 1] == '\n')              // case where user enters >= 100 characters (size of 'userInput')
        {
            userInput[len - 1] = '\0';
        }

        parseInput(userInput);
    }
    else
    {
        printf("Error reading input.\n");
    }

    return 0;
}