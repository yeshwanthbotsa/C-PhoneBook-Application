#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void delete_contact(Contact **head)
{
    char name[NAME_LEN];
    Contact *temp;
    Contact *prev;

    if (*head == NULL)
    {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter contact name to delete: ");
    get_non_empty_string(name, NAME_LEN);

    temp = *head;
    prev = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Contact deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Contact not found.\n");
}
