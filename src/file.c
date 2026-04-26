#include <stdio.h>
#include <string.h>
#include "../include/file.h"

int loadContacts(struct Contact contacts[], int max) {
    FILE *fp = fopen(DATA_FILE, "r");
    int count = 0;

    if (fp == NULL) {
        printf("[Info] No existing contacts file found. Starting fresh.\n");
        return 0;
    }

    while (count < max && 
           fscanf(fp, "%49[^|]|%14[^|]|%49[^\n]\n", 
                  contacts[count].name, 
                  contacts[count].phone, 
                  contacts[count].email) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}

int saveContacts(const struct Contact contacts[], int count) {
    int i;
    FILE *fp = fopen(DATA_FILE, "w");

    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return 0;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%s|%s|%s\n", 
                contacts[i].name, 
                contacts[i].phone, 
                contacts[i].email);
    }

    fclose(fp);
    return 1;
}

