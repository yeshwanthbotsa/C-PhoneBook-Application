#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define NAME_LEN 50
#define PHONE_LEN 20
#define EMAIL_LEN 60
#define ADDRESS_LEN 120
#define MAX_NUMBERS 5
#define DATA_FILE "phonebook.dat"

typedef struct Contact
{
    char name[NAME_LEN];
    char phone[MAX_NUMBERS][PHONE_LEN];
    int phone_count;
    char email[EMAIL_LEN];
    char address[ADDRESS_LEN];
    struct Contact *next;
} Contact;

void create_contact(Contact **head);
void print_contacts(Contact *head);
void delete_contact(Contact **head);
void find_contact(Contact *head);
void edit_contact(Contact *head);
void save_contacts(Contact *head);
void syncfile(Contact **head);
void load_contacts(Contact **head);
void free_contacts(Contact *head);

Contact *find_by_name(Contact *head, char *name);
Contact *new_contact(void);
void print_one_contact(Contact *contact);
void get_string(char *str, int size);
void get_non_empty_string(char *str, int size);
int get_yes_no(char *message);
void clear_input_buffer(void);

#endif
