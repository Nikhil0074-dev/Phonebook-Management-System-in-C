#include <stdio.h>
#include <string.h>
#include "../include/contact.h"
#include "../include/file.h"
#include "../include/add.h"
#include "../include/search.h"
#include "../include/update.h"
#include "../include/delete.h"

/* Common utility functions declared in contact.h */

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void displayContact(const struct Contact *c) {
    printf("Name  : %s\n", c->name);
    printf("Phone : %s\n", c->phone);
    printf("Email : %s\n", c->email);
    printf("--------------------------\n");
}

void pauseScreen(void) {
    printf("\nPress Enter to continue...");
    getchar();
}

static void displayMenu(void) {
    printf("\n--- Phonebook Management System ---\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Update Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Display All Contacts\n");
    printf("0. Exit\n");
    printf("-----------------------------------\n");
}

static void displayAllContacts(const struct Contact contacts[], int count) {
    int i;
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("\n--- All Contacts (%d) ---\n", count);
    for (i = 0; i < count; i++) {
        displayContact(&contacts[i]);
    }
}

int main(void) {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    count = loadContacts(contacts, MAX_CONTACTS);
    if (count > 0) {
        printf("[Info] Loaded %d contact(s) from file.\n", count);
    }

    do {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                if (saveContacts(contacts, count)) {
                    printf("[Info] Contacts saved to file.\n");
                }
                break;
            case 2:
                searchContact(contacts, count);
                break;
            case 3:
                updateContact(contacts, count);
                if (saveContacts(contacts, count)) {
                    printf("[Info] Contacts saved to file.\n");
                }
                break;
            case 4:
                deleteContact(contacts, &count);
                if (saveContacts(contacts, count)) {
                    printf("[Info] Contacts saved to file.\n");
                }
                break;
            case 5:
                displayAllContacts(contacts, count);
                break;
            case 0:
                printf("\nSaving data and exiting...\n");
                saveContacts(contacts, count);
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice != 0) {
            pauseScreen();
        }

    } while (choice != 0);

    return 0;
}

