#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void edit_contact(Contact *head)
{
    char name[NAME_LEN];
    char choice;
    Contact *temp;
    int i;

    printf("Enter contact name to edit: ");
    get_non_empty_string(name, NAME_LEN);

    temp = find_by_name(head, name);

    if (temp == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    while (1)
    {
        printf("\n--------- EDIT MENU ---------\n");
        printf("1. Change name\n");
        printf("2. Change phone numbers\n");
        printf("3. Change email\n");
        printf("4. Change address\n");
        printf("5. Add another phone number\n");
        printf("6. Done\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        clear_input_buffer();

        if (choice == '1')
        {
            char new_name[NAME_LEN];
            printf("Enter new name: ");
            get_non_empty_string(new_name, NAME_LEN);

            if (strcmp(new_name, temp->name) != 0 && find_by_name(head, new_name) != NULL)
            {
                printf("Another contact already has this name.\n");
            }
            else
            {
                strcpy(temp->name, new_name);
                printf("Name updated.\n");
            }
        }
        else if (choice == '2')
        {
            printf("Current phone numbers:\n");
            for (i = 0; i < temp->phone_count; i++)
            {
                printf("%d. %s\n", i + 1, temp->phone[i]);
            }

            printf("Enter phone number to change (1-%d): ", temp->phone_count);
            scanf("%d", &i);
            clear_input_buffer();

            if (i >= 1 && i <= temp->phone_count)
            {
                printf("Enter new phone number: ");
                get_non_empty_string(temp->phone[i - 1], PHONE_LEN);
                printf("Phone number updated.\n");
            }
            else
            {
                printf("Invalid number.\n");
            }
        }
        else if (choice == '3')
        {
            printf("Enter new email: ");
            get_string(temp->email, EMAIL_LEN);
            printf("Email updated.\n");
        }
        else if (choice == '4')
        {
            printf("Enter new address: ");
            get_string(temp->address, ADDRESS_LEN);
            printf("Address updated.\n");
        }
        else if (choice == '5')
        {
            if (temp->phone_count >= MAX_NUMBERS)
            {
                printf("Maximum %d phone numbers allowed.\n", MAX_NUMBERS);
            }
            else
            {
                printf("Enter new phone number: ");
                get_non_empty_string(temp->phone[temp->phone_count], PHONE_LEN);
                temp->phone_count++;
                printf("Phone number added.\n");
            }
        }
        else if (choice == '6')
        {
            printf("Editing completed.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
}
