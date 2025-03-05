CC = gcc
CFLAGS = -Wall -g -Iinclude
OBJ_DIR = build
BIN_DIR = bin
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core

SRC_FILES = $(SRC_DIR)/main.c \
            $(CORE_DIR)/database.c $(CORE_DIR)/insert_user.c $(CORE_DIR)/read_user.c \
            $(CORE_DIR)/delete_user.c $(CORE_DIR)/wal.c $(CORE_DIR)/vacuum.c

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TARGET = $(BIN_DIR)/my_database_project

# Build the main executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: clean
