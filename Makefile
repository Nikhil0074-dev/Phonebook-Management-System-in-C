CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./include
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/phonebook.exe

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

.PHONY: all clean dirs run

all: dirs $(TARGET)

dirs:
	if not exist $(OBJDIR) mkdir $(OBJDIR)
	if not exist $(BINDIR) mkdir $(BINDIR)
	if not exist data mkdir data

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
	if exist $(BINDIR) rmdir /s /q $(BINDIR)

run: all
	$(TARGET)

