#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void create_contact(Contact **head)
{
    Contact *new_node;
    Contact *temp;
    int i;

    new_node = new_contact();
    if (new_node == NULL)
        return;

    printf("\nEnter contact name: ");
    get_non_empty_string(new_node->name, NAME_LEN);

    if (find_by_name(*head, new_node->name) != NULL)
    {
        printf("Contact already exists with this name.\n");
        free(new_node);
        return;
    }

    printf("Enter phone number 1: ");
    get_non_empty_string(new_node->phone[0], PHONE_LEN);
    new_node->phone_count = 1;

    while (new_node->phone_count < MAX_NUMBERS)
    {
        if (get_yes_no("Do you want to add another number to the same name (Y/N): "))
        {
            printf("Enter phone number %d: ", new_node->phone_count + 1);
            get_non_empty_string(new_node->phone[new_node->phone_count], PHONE_LEN);
            new_node->phone_count++;
        }
        else
        {
            break;
        }
    }

    if (get_yes_no("Do you want to add email (Y/N): "))
    {
        printf("Enter email: ");
        get_string(new_node->email, EMAIL_LEN);
    }

    if (get_yes_no("Do you want to add address (Y/N): "))
    {
        printf("Enter address: ");
        get_string(new_node->address, ADDRESS_LEN);
    }

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    printf("Contact created successfully.\n");

    for (i = new_node->phone_count; i < MAX_NUMBERS; i++)
    {
        new_node->phone[i][0] = '\0';
    }
}
