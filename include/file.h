#ifndef FILE_H
#define FILE_H

#include "contact.h"

#define DATA_FILE "data/contacts.txt"

int loadContacts(struct Contact contacts[], int max);
int saveContacts(const struct Contact contacts[], int count);

#endif

