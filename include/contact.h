#ifndef CONTACT_H
#define CONTACT_H

#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_EMAIL 50
#define MAX_CONTACTS 500

struct Contact {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
};

void clearInputBuffer(void);
void trimNewline(char *str);
void displayContact(const struct Contact *c);
void pauseScreen(void);

#endif

