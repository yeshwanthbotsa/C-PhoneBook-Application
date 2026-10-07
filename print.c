#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void print_contacts(Contact *head)
{
    Contact *temp = head;
    int count = 0;

    if (head == NULL)
    {
        printf("Phone book is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        print_one_contact(temp);
        count++;
        temp = temp->next;
    }

    printf("Total contacts: %d\n", count);
}
