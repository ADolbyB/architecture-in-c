/**
 * Joel Brigida
 * CDA-4102: Computer Architecture
 * This is a Parser example that uses an FSM (Finite State Machine)
 * to determine if the user entered input is valid.
 * This code has been adapted and modified from this source:
 * 
 * https://www.quora.com/What-are-some-better-alternatives-to-scanf-in-C-and-what-do-they-do-exactly
 * 
 * This subroutine is designed to parse a series of numbers separated by commas and whitespace.
 * The parameter value is set to the value of the integer parsed if the return value is true and contains an 
 * error code if the return value is false. In C++, I would throw an exception instead.
 * 
 * Note from author after asked "What are some better alternatives to "scanf" in C, and what do they do exactly?"
 * 
 * I write my own parsers. It doesn’t take all that long, I know what I am getting out of it, I can do whatever 
 * I choose to do on an error, and I’d rather spend the time getting it right than waste time trying to figure 
 * out how to get around all the scanf failure modes.
 * It is very easy to write an FSM in C/C++. This is the sort of code I would write in Windows. UINT is uint32_t 
 * and TCHAR is either int8_t or int16_t depending on compilation options; _T() creates either an 8-bit or 16-bit 
 * character based on the same compilation options. Feel free to translate to your favorite language. What works 
 * well in C/C++ but not in Java or some other languages is the ST() macro generates a compile-time constant 
 * value, necessary for the switch statement. Note also that in C++, I generally have a generic abstract class 
 * lexeme, and I return a subclass, such as LexNumber, which holds a number, or LexString, which holds a string. 
 * This is a fairly trivial parser for a number. I am writing this from memory so I can time myself as to how 
 * long it took to write it; it advances the string pointer s to point to the next place to start the parse.
 * This subroutine is designed to parse a series of numbers separated by commas and whitespace. The parameter 
 * value is set to the value of the integer parsed if the return value is true and contains an error code if the 
 * return value is false. In C++, I would throw an exception instead.
 * 
*/

#include <stddef.h>                                                     // size_t definition
#include <stdio.h>

#define EMPTY_STRING 0
#define ILLEGAL_CHARACTER -1
#define INTERNAL_ERROR -2
#define ST(state, ch) (((UINT)(state) << 8) | (ch))

static const char CR = '\r'; 
static const char LF = '\n'; 
static const char TAB = '\t'; 
static const char EOS = 0; 

typedef unsigned int UINT;

typedef enum {
    S0,                                                                 // beginning state before user enters input
    SAW_DIGIT,                                                          // state that sees integer user input
    NUMBER_DONE             
} STATES;

STATES state = S0;

bool ParseNumber(const char *& s, UINT& value) 
{ 
    value = 0; 
    while(true) 
    {   
        /* lexer loop */ 
        char ch = *s; 
        s++;
        switch(ST(state, ch))                                           /* FSM */ 
        {
            case ST(S0, EOS): 
            case ST(S0, CR):
            case ST(S0, LF): 
            case ST(S0, ','):
                value = EMPTY_STRING; 
                return false;                                           // empty string 
            case ST(S0, ' '): 
            case ST(S0, TAB): 
                continue;                                               // ignore leading whitespace 
            case ST(S0, '0'): 
            case ST(S0, '1'): 
            case ST(S0, '2'): 
            case ST(S0, '3'): 
            case ST(S0, '4'): 
            case ST(S0, '5'): 
            case ST(S0, '6'): 
            case ST(S0, '7'): 
            case ST(S0, '8'): 
            case ST(S0, '9'): 
                state = SAW_DIGIT; 
                value = (ch - '0'); 
                continue; 
            case ST(SAW_DIGIT, '0'): 
            case ST(SAW_DIGIT, '1'): 
            case ST(SAW_DIGIT, '2'): 
            case ST(SAW_DIGIT, '3'): 
            case ST(SAW_DIGIT, '4'): 
            case ST(SAW_DIGIT, '5'): 
            case ST(SAW_DIGIT, '6'): 
            case ST(SAW_DIGIT, '7'): 
            case ST(SAW_DIGIT, '8'): 
            case ST(SAW_DIGIT, '9'): 
                value = value * 10 + (ch - '0'); 
                continue; 
            case ST(SAW_DIGIT, ','): 
                s++; 
                return true; 
            case ST(SAW_DIGIT, EOS): 
                return true; 
            case ST(SAW_DIGIT, CR): 
            case ST(SAW_DIGIT, LF): 
            case ST(SAW_DIGIT, ' '): 
            case ST(SAW_DIGIT, TAB): 
                state = NUMBER_DONE; 
                continue; 
            case ST(NUMBER_DONE, EOS): 
                return true; 
            case ST(NUMBER_DONE, CR): 
            case ST(NUMBER_DONE, LF): 
            case ST(NUMBER_DONE, ' '): 
            case ST(NUMBER_DONE, TAB): 
                continue; 
            case ST(NUMBER_DONE, ','): 
                s++; 
                return true; 
            default: 
                switch(state)                                           /* error reporting */
                {
                    case S0: 
                    case SAW_DIGIT: 
                        value = ILLEGAL_CHARACTER; 
                        return false; 
                    case NUMBER_DONE:                                   // *s is now pointing at the character that terminated the scan 
                        return true; 
                    default:                                            // should never get here 
                        value = INTERNAL_ERROR; 
                        return false; 
                }   /* error reporting */ 
        }   /* FSM */ 
    }   /* lexer loop */
}

int main()
{
    const char* input;
    UINT value;

    printf("Enter a number followed by a comma: ");                     // Prompt the user for input

    char* userInput = NULL;                                             // Begin variables for `getline()`
    size_t bufferSize = 0;                                              // 'size_t' = size in bytes (unsigned int)
    ssize_t inputLength = getline(&userInput, &bufferSize, stdin);      // 'ssize_t' represents the sizes of blocks that can be read or written in a single operation

    if (inputLength > 0)
    {
        if (userInput[inputLength - 1] == '\n')                         // Remove the newline character at the end of the input (if any)
        {
            userInput[inputLength - 1] = '\0';
        }

        input = userInput;
        if (ParseNumber(input, value))                                  // Pass the user's input to the FSM parser
        {
            printf("User Entered: %u\n", value);
        }
        else
        {
            printf("INVALID INPUT...\n");
        }
    }
    else                                                                // should not happen
    {
        printf("Error reading input.\n");
    }

    return 0;
}