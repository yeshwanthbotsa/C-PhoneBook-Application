#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

Contact *find_by_name(Contact *head, char *name)
{
    Contact *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}
