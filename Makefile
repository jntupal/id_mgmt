# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target executable
TARGET = id_program

# Source files
SRCS_MAIN = id_main.c
SRCS_LIB = id_mgmt.c queue.c

# Object files
OBJS_MAIN = $(SRCS_MAIN:.c=.o)
OBJS_LIB = $(SRCS_LIB:.c=.o)

# Library name
LIBRARY = libid_mgmt.a

# Default target
all: $(LIBRARY) $(TARGET)

# Build the library
$(LIBRARY): $(OBJS_LIB)
	ar rcs $(LIBRARY) $(OBJS_LIB)

# Build the target executable
$(TARGET): $(OBJS_MAIN) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS_MAIN) $(LIBRARY)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS_MAIN) $(OBJS_LIB) $(TARGET) $(LIBRARY)

# Phony targets
.PHONY: all clean

