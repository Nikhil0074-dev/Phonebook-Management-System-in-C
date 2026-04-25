# Phonebook Management System in C

A console-based contact management application developed in C with file handling for data persistence.

## Features

- Add new contacts (Name, Phone, Email)
- Search contacts by Name or Phone number
- Update existing contact details
- Delete contacts with confirmation
- Display all saved contacts
- Automatic save/load from file

## Project Structure

```
phonebook-system/
|
├── src/
│   ├── main.c          (Entry point and menu)
│   ├── add.c           (Add contact logic)
│   ├── search.c        (Search by name/phone)
│   ├── update.c        (Modify contact)
│   ├── delete.c        (Remove contact)
│   └── file.c          (Load/save data)
|
├── include/
│   ├── contact.h       (Common struct and utilities)
│   ├── add.h
│   ├── search.h
│   ├── update.h
│   ├── delete.h
│   └── file.h
|
├── data/
│   └── contacts.txt    (Persistent storage)
|
├── Makefile
├── build.bat
└── README.md
```

## Build Instructions

### Using build.bat (Windows)
```cmd
cd phonebook-system
build.bat
```

### Using Makefile (requires MinGW or similar)
```cmd
cd phonebook-system
make
```

### Manual Compilation
```cmd
cd phonebook-system
gcc -Wall -Wextra -std=c99 -I./include src/main.c src/file.c src/add.c src/search.c src/update.c src/delete.c -o bin/phonebook.exe
```

## Run

```cmd
bin\phonebook.exe
```

## Data Format

Contacts are stored in `data/contacts.txt` using pipe-delimited format:
```
Name|Phone|Email
```

## Sample Output

```
--- Phonebook Management System ---
1. Add Contact
2. Search Contact
3. Update Contact
4. Delete Contact
5. Display All
0. Exit
-----------------------------------
Enter choice: 1

--- Add New Contact ---
Enter Name: Rahul
Enter Phone: 9876543210
Enter Email: rahul@gmail.com
Contact added successfully!
[Info] Contacts saved to file.
```

## Future Enhancements

- Sorting contacts alphabetically
- Duplicate detection
- Password protection
- GUI version
- Database integration (SQLite)
- Import/export CSV

## Conclusion

This project demonstrates:
- File handling in C
- Data structures (struct)
- CRUD operations (Create, Read, Update, Delete)
- Modular programming

Ideal for mini projects, lab exams, and programming practice.

