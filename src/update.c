#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/update.h"
#include "../include/contact.h"

static int strCaseCmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

void updateContact(struct Contact contacts[], int count) {
    int i, found = 0, choice;
    char query[MAX_NAME];

    if (count == 0) {
        printf("No contacts available to update.\n");
        return;
    }

    printf("\n--- Update Contact ---\n");
    printf("Enter Name or Phone of contact to update: ");
    clearInputBuffer();
    fgets(query, MAX_NAME, stdin);
    trimNewline(query);

    for (i = 0; i < count; i++) {
        if (strCaseCmp(contacts[i].name, query) || 
            strCaseCmp(contacts[i].phone, query)) {
            found = 1;
            printf("\nContact found:\n");
            displayContact(&contacts[i]);

            printf("\nWhat do you want to update?\n");
            printf("1. Name\n");
            printf("2. Phone\n");
            printf("3. Email\n");
            printf("4. Multiple fields\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            clearInputBuffer();

            switch (choice) {
                case 1:
                    printf("Enter new Name: ");
                    fgets(contacts[i].name, MAX_NAME, stdin);
                    trimNewline(contacts[i].name);
                    break;
                case 2:
                    printf("Enter new Phone: ");
                    fgets(contacts[i].phone, MAX_PHONE, stdin);
                    trimNewline(contacts[i].phone);
                    break;
                case 3:
                    printf("Enter new Email: ");
                    fgets(contacts[i].email, MAX_EMAIL, stdin);
                    trimNewline(contacts[i].email);
                    break;
                case 4:
                    printf("Enter new Name: ");
                    fgets(contacts[i].name, MAX_NAME, stdin);
                    trimNewline(contacts[i].name);
                    printf("Enter new Phone: ");
                    fgets(contacts[i].phone, MAX_PHONE, stdin);
                    trimNewline(contacts[i].phone);
                    printf("Enter new Email: ");
                    fgets(contacts[i].email, MAX_EMAIL, stdin);
                    trimNewline(contacts[i].email);
                    break;
                default:
                    printf("Invalid choice. No changes made.\n");
                    return;
            }

            printf("Contact updated successfully!\n");
            return;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

