#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/search.h"
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

static int strContainsIgnoreCase(const char *haystack, const char *needle) {
    int i, j;
    int hlen = strlen(haystack);
    int nlen = strlen(needle);

    if (nlen == 0) return 1;
    if (nlen > hlen) return 0;

    for (i = 0; i <= hlen - nlen; i++) {
        int match = 1;
        for (j = 0; j < nlen; j++) {
            if (tolower((unsigned char)haystack[i + j]) != tolower((unsigned char)needle[j])) {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void searchContact(const struct Contact contacts[], int count) {
    int choice, i, found = 0;
    char query[MAX_NAME];

    if (count == 0) {
        printf("No contacts available to search.\n");
        return;
    }

    printf("\n--- Search Contact ---\n");
    printf("1. Search by Name\n");
    printf("2. Search by Phone\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

    if (choice != 1 && choice != 2) {
        printf("Invalid choice.\n");
        return;
    }

    printf("Enter search query: ");
    fgets(query, MAX_NAME, stdin);
    trimNewline(query);

    printf("\n--- Search Results ---\n");
    for (i = 0; i < count; i++) {
        int match = 0;
        if (choice == 1) {
            match = strContainsIgnoreCase(contacts[i].name, query);
        } else {
            match = strCaseCmp(contacts[i].phone, query);
        }

        if (match) {
            displayContact(&contacts[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contacts found.\n");
    }
}

