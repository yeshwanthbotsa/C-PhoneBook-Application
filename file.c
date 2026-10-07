#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

int size = sizeof(Contact) - sizeof(Contact *);

void save_contacts(Contact *head)
{
    FILE *fp;
    Contact *temp;

    fp = fopen(DATA_FILE, "w");

    if (fp == NULL)
    {
        printf("Unable to open file for saving.\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        fwrite(temp, size, 1, fp);
        temp = temp->next;
    }

    fclose(fp);

    printf("Contacts saved successfully.\n");
}

void load_contacts(Contact **head)
{
    FILE *fp;
    Contact temp;
    Contact *new_node;
    Contact *last;

    fp = fopen(DATA_FILE, "r");

    if (fp == NULL)
    {
        return;
    }

    last = NULL;

    while (fread(&temp, size, 1, fp) == 1)
    {
        new_node = new_contact();

        if (new_node == NULL)
        {
            fclose(fp);
            return;
        }

        strcpy(new_node->name, temp.name);

        new_node->phone_count = temp.phone_count;

        for (int i = 0; i < temp.phone_count; i++)
        {
            strcpy(new_node->phone[i], temp.phone[i]);
        }

        strcpy(new_node->email, temp.email);
        strcpy(new_node->address, temp.address);

        new_node->next = NULL;

        if (*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            last->next = new_node;
        }

        last = new_node;
    }

    fclose(fp);
}
