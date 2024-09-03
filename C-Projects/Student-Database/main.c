#include "main.h"

void display_menu()
{
    printf("Enter choice of operation from the menu below.\n\n");
    printf("==== MENU OF OPERATIONS ====\n");
    printf("1. Get an integer input.\n");
    printf("2. Get a string input.\n");
    printf("3. Do nothing.\n");
    printf("Exit the program.\n\n");
}


int main()
{
    int val;
    const char* str;

    val = get_integer_input("Enter an integer: ");
    printf("You entered the value: %d\n\n", val);

    str = get_string_input("Enter a string:  ");
    printf("You enterd the string: %s\n\n", str);

    return (0);
}