#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

Contact *new_contact(void)
{
    Contact *new_node;

    new_node = (Contact *)malloc(sizeof(Contact));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    memset(new_node, 0, sizeof(Contact));
    new_node->next = NULL;

    return new_node;
}
