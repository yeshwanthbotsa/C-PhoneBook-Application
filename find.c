#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void find_contact(Contact *head)
{
    char name[NAME_LEN];
    Contact *temp;

    printf("Enter contact name to find: ");
    get_non_empty_string(name, NAME_LEN);

    temp = find_by_name(head, name);

    if (temp == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    print_one_contact(temp);
}
