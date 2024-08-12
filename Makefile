# Compiler

CC = gcc
CFLAGS = -Wall Iinclude

#Directories

SRC_DIR = src 
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin 

#Output for the binary name

TARGET = $(BIN_DIR)/file_organizer

#Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

#Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#Default target
all: $(TARGET)

#Linking the object files to create the binary 
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

#Compiling the source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#Cleaning up the build
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

#Phony targets
.PHONY: all clean
