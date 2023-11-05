# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c11 -O0

# Directories
SRCDIR = src
BINDIR = .

# Source and object files
SOURCES := $(wildcard $(SRCDIR)/*.c)
BINS := $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%,$(SOURCES))

.PHONY: all clean

all: $(BINS)

$(BINDIR)/%: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BINS)
