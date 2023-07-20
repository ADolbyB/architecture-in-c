/**
 * Joel Brigida
 * CDA-4102: Computer Architecture
 * This is a Parser example that uses an FSM (Finite State Machine)
 * to determine if the user entered input is valid.
 * This model can be modified to accomodate different needs.
 * 
 * This subroutine is designed to parse a series of numbers separated by commas and whitespace.
 * The parameter value is set to the value of the integer parsed if the return value is true and contains an 
 * error code if the return value is false. In C++, I would throw an exception instead.
*/

#include <stddef.h>                                             // defines 'size_t'
#include <stdio.h>

#define EMPTY_STRING 0
#define ILLEGAL_CHARACTER -1
#define INTERNAL_ERROR -2
#define CR '\r'
#define LF '\n'
#define TAB '\t'
#define EOS 0

typedef unsigned int UINT;

typedef enum {
    S0, 
    SAW_DIGIT, 
    NUMBER_DONE
} STATES;

STATES state = S0;

int ParseNumber(const char *s, UINT *value)
{ 
    *value = 0; 
    while(1)                                         /* lexer loop */
    {   
        /* lexer loop */ 
        char ch = *s; 
        s++; 

        switch(state)                               /* outer switch for states */
        {
            case S0:                                // case where beginning of the 
                switch(ch)                          /* inner switch for S0 */
                {   
                    case EOS:                       // End of String
                    case CR:                        // Carriage Return (home key)
                    case LF:                        // Line Feed
                    case ',':
                        *value = EMPTY_STRING;      // Treat all these cases as EMPTY_STRING
                        return 0;                   // return from function.
                    case ' ':                       // whitespace character (ignore)
                    case TAB:                       // whitespace character (ignore)
                        continue;                   // continue parsing (input is valid).
                    case '0': 
                    case '1': 
                    case '2': 
                    case '3': 
                    case '4': 
                    case '5': 
                    case '6': 
                    case '7': 
                    case '8': 
                    case '9': 
                        state = SAW_DIGIT; 
                        *value = (ch - '0'); 
                        continue;                   // continue parsing (input is valid).
                    default:
                        *value = ILLEGAL_CHARACTER; 
                        return 0;                   // return from function if (0-9) is not received
                }
                break;

            case SAW_DIGIT:
                switch(ch)                          /* inner switch for SAW_DIGIT */
                {
                    case '0': 
                    case '1': 
                    case '2': 
                    case '3': 
                    case '4': 
                    case '5': 
                    case '6': 
                    case '7': 
                    case '8': 
                    case '9': 
                        *value = *value * 10 + (ch - '0'); 
                        continue; 
                    case ',':
                        s++; 
                        return 1; 
                    case EOS:
                        return 1; 
                    case CR:
                    case LF:
                    case ' ':
                    case TAB:
                        state = NUMBER_DONE; 
                        continue; 
                    default:
                        *value = ILLEGAL_CHARACTER; 
                        return 0; 
                }
                break;

            case NUMBER_DONE:
                switch(ch)                          /* inner switch for NUMBER_DONE */
                {
                    case EOS:
                        return 1; 
                    case CR:
                    case LF:
                    case ' ':
                    case TAB:
                        continue; 
                    case ',':
                        s++; 
                        return 1; 
                    default:
                        *value = ILLEGAL_CHARACTER; 
                        return 0; 
                }
                break;

            default:
                *value = INTERNAL_ERROR; 
                return 0; 
        }   // End Outer switch()
    }   // END switch for the state
}   // END while()


int main()
{
    const char* input;
    UINT value;

    printf("Enter a number followed by a comma: ");                 // Prompt the user for input
    
    char userInput[100];                                            // Read the user's input
    scanf("%99s", userInput);                                       // Read up to 99 characters: leave room for '\0'

    input = userInput;                                              // Pass the user's input to the FSM parser
    if (ParseNumber(input, &value))
    {
        printf("Parsed number: %u\n", value);
    }
    else
    {
        printf("Parsing failed.\n");
    }

    return 0;
}