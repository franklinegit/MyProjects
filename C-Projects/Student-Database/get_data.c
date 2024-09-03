#include "main.h"

#define MAX_INPUT_SIZE 100

int get_integer_input0(const char* prompt)
{
    /*Define variable to store input*/
    /*Validate if the input is an integer*/
    /*Loop to start if input isn't integer or does not fit criteria until right input is given*/
    /*Return integer input*/
    
    int input;
    do
    {
        printf("%s", prompt);
        if (scanf("%d", &input) != 1)
        {
            fprintf(stderr, "Error. Your input was not of intended type: %s.\n", strerror(errno));
            clear_input_buffer();
            printf("Please try again.\n\n");
        }
        else
            break;
    } while (1);
    
    return (input);
}

void clear_input_buffer()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}


int get_integer_input(const char* prompt)
{
    int input;
    char buffer[MAX_INPUT_SIZE];

    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            long val;
            char* endptr;
            errno = 0;

            val = strtol(buffer, &endptr, 10);

            if (endptr == buffer || *endptr != '\n')
            {
                fprintf(stderr, "Error: NO valid integer entered. Please try again.\n\n");
            }
            else if (errno == ERANGE || val < INT_MIN || val > INT_MAX)
            {
                fprintf(stderr, "Error: The integer is out of range. Please try again.\n\n");
            }
            else
            {
                input = (int)val;
                break;
            }
        }

        else
        {
            fprintf(stderr, "Error: Could not read input. Please try again.\n\n");
        }

        clear_input_buffer();
    }
    
    return (input);
}


char* get_string_input(const char* prompt)
{
    char* str;                      /*Pointer to store validated string*/
    char buffer[MAX_INPUT_SIZE];    /*Buffer to store input string*/
    size_t len;                     /*Length of input string*/

    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            len = strlen(buffer);
            /*if string length > 0 and ends with new-line character*/
            /*Remove new-line character if any*/
            if (len > 0 && buffer[len - 1] == '\n')
            {
                buffer[len - 1] = '\0';
            }

            else if (len == 0)
            {
                /*There's no input*/
                fprintf(stderr, "Error: No input entered. Please try again.\n\n");
                continue;
            }

            else
            {
                /*If the buffer is full but the last character isn't a newline character. Clear input buffer*/
                clear_input_buffer();
                fprintf(stderr, "Error: The input was too long. Please try again.\n\n");
                continue;
            }

            /*Allocate memory for validated string*/
            str = malloc(strlen(buffer) + 1);
            if (str == NULL)
            {
                fprintf(stderr, "Error: Could not allocate memory for the validated string.\n\n");
                exit(EXIT_FAILURE);
            }

            strcpy(str, buffer);    /*Copy validated string into allocated memory*/
            break;  /*Break the loop if everything is in order*/
        }

        else
        {
            /*If fgets fails to read input from stdin. Clear buffer.*/
            fprintf(stderr, "Error: Could not read input from the stdin. Please try again.\n\n");
            clear_input_buffer();
        }
    }
    
    return (str); /*Return validated string*/
}