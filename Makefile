# Define compiler and flags
CC = gcc
CFLAGS = -Wall -g
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include

# List of source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/database.c $(SRC_DIR)/insert_user.c $(SRC_DIR)/read_user.c $(SRC_DIR)/sql_interpreter.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Name of the final executable
TARGET = my_database_project


$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

# Rule for compiling .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -I$(INCLUDE_DIR) $< -o $@

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: clean
