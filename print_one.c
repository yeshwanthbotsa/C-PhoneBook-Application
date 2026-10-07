#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void print_one_contact(Contact *contact)
{
    int i;

    printf("\n---------------------------------------------\n");
    printf("Name    : %s\n", contact->name);

    for (i = 0; i < contact->phone_count; i++)
    {
        printf("Phone %d : %s\n", i + 1, contact->phone[i]);
    }

    if (strlen(contact->email) > 0)
        printf("Email   : %s\n", contact->email);
    else
        printf("Email   : Not available\n");

    if (strlen(contact->address) > 0)
        printf("Address : %s\n", contact->address);
    else
        printf("Address : Not available\n");

    printf("---------------------------------------------\n");
}
