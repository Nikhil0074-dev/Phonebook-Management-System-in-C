#include <stdio.h>
#include <string.h>
#include "../include/add.h"
#include "../include/contact.h"

void addContact(struct Contact contacts[], int *count) {
    struct Contact newContact;

    if (*count >= MAX_CONTACTS) {
        printf("Error: Phonebook is full. Cannot add more contacts.\n");
        return;
    }

    printf("\n--- Add New Contact ---\n");
    clearInputBuffer();
    printf("Enter Name: ");
    fgets(newContact.name, MAX_NAME, stdin);
    trimNewline(newContact.name);

    printf("Enter Phone: ");
    fgets(newContact.phone, MAX_PHONE, stdin);
    trimNewline(newContact.phone);

    printf("Enter Email: ");
    fgets(newContact.email, MAX_EMAIL, stdin);
    trimNewline(newContact.email);

    if (strlen(newContact.name) == 0 || strlen(newContact.phone) == 0) {
        printf("Error: Name and Phone are required fields.\n");
        return;
    }

    contacts[*count] = newContact;
    (*count)++;

    printf("Contact added successfully!\n");
}

