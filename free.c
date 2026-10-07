#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void free_contacts(Contact *head)
{
    Contact *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
