#include "main.h"

void display_menu()
{
    printf("==== MENU OF OPERATIONS ====\n");
    printf("1. Get an integer input.\n");
    printf("2. Get a string input.\n");
    printf("3. Do nothing.\n");
    printf("4 .Exit the program.\n\n");
}


int main()
{
    while (1)
    {
        int choice;
        int val;
        const char* str;

        display_menu();
        choice = get_integer_input("Enter choice of operation from the menu: ");
        printf("\n");

        switch (choice)
        {
            case 1:
                printf("Getting integer...\n");
                val = get_integer_input("Enter an integer: ");
                printf("You entered the value: %d\n\n", val);
                break;

            case 2:
                printf("Getting string...\n");
                str = get_string_input("Enter a string: ");
                printf("You entered the string: %s\n\n", str);
                break;
            
            case 3:
                continue;

            case 4:
                printf("Exiting the program....\n");
                exit(0);

            default:
                printf("Please Enter a valid choice between 1 and 4.\n\n");
                break;
        }
    }

    return (0);
}