#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/delete.h"
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

void deleteContact(struct Contact contacts[], int *count) {
    int i, j, found = 0;
    char query[MAX_NAME];
    char confirm;

    if (*count == 0) {
        printf("No contacts available to delete.\n");
        return;
    }

    printf("\n--- Delete Contact ---\n");
    printf("Enter Name or Phone of contact to delete: ");
    clearInputBuffer();
    fgets(query, MAX_NAME, stdin);
    trimNewline(query);

    for (i = 0; i < *count; i++) {
        if (strCaseCmp(contacts[i].name, query) || 
            strCaseCmp(contacts[i].phone, query)) {
            found = 1;
            printf("\nContact found:\n");
            displayContact(&contacts[i]);

            printf("\nAre you sure you want to delete this contact? (y/n): ");
            scanf(" %c", &confirm);
            clearInputBuffer();

            if (confirm == 'y' || confirm == 'Y') {
                for (j = i; j < *count - 1; j++) {
                    contacts[j] = contacts[j + 1];
                }
                (*count)--;
                printf("Contact deleted successfully!\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            return;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

