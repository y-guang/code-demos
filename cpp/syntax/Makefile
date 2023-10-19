# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directories
SRCDIR = src
BINDIR = .

# Source and object files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
BINS := $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%,$(SOURCES))

.PHONY: all clean

all: $(BINS)

$(BINDIR)/%: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(BINS)
