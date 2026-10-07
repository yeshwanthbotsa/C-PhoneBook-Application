#include <stdio.h>
#include <string.h>
#include "phonebook.h"

void clear_input_buffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

void get_string(char *str, int size)
{
    if (fgets(str, size, stdin) != NULL)
    {
        str[strcspn(str, "\n")] = '\0';
    }
}

void get_non_empty_string(char *str, int size)
{
    do
    {
        get_string(str, size);
        if (strlen(str) == 0)
            printf("Input cannot be empty. Enter again: ");
    } while (strlen(str) == 0);
}

int get_yes_no(char *message)
{
    char choice;

    while (1)
    {
        printf("%s", message);
        scanf(" %c", &choice);
        clear_input_buffer();

        if (choice == 'y' || choice == 'Y')
            return 1;

        if (choice == 'n' || choice == 'N')
            return 0;

        printf("Please enter Y or N.\n");
    }
}
