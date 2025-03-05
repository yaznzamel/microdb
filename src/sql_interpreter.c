#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  // For toupper function
#include "database.h"
#include "sql_interpreter.h"

// Function to handle INSERT INTO command
void handle_insert(const char *query) {
    // Format: INSERT INTO users (id, name, age) VALUES (1, 'Alice', 30);
    int id;
    char name[100];
    int age;

    // Simple parsing of the query (in a real system, you'd use a proper parser)
    if (sscanf(query, "INSERT INTO users (id, name, age) VALUES (%d, '%99[^']', %d);", &id, name, &age) == 3) {
        Record rec = {id, "", age}; // Initialize with id and age
        strncpy(rec.name, name, sizeof(rec.name));  // Copy the name to the Record
        insert_user("bin/database.dat", &rec);  // Insert the record into the file
        printf("Record inserted: ID=%d, Name=%s, Age=%d\n", id, rec.name, age);
    } else {
        printf("Invalid INSERT query.\n");
    }
}

// Function to handle SELECT * FROM users command
void handle_select(const char *query) {
    // Simple SELECT statement
    if (strncmp(query, "SELECT * FROM users;", 20) == 0) {
        select_users("bin/database.dat");  // Display all users in the database
    } else {
        printf("Invalid SELECT query.\n");
    }
}

// Function to handle DELETE FROM users WHERE id = <id> command
void handle_delete(const char *query) {
    // Format: DELETE FROM users WHERE id = 1;
    int id;
    
    if (sscanf(query, "DELETE FROM users WHERE id = %d;", &id) == 1) {
        delete_user("bin/database.dat", id);  // Delete user with given id
    } else {
        printf("Invalid DELETE query.\n");
    }
}

// SQL Interpreter function
void sql_interpreter(const char *query) {
    // Convert query to uppercase for case-insensitive comparison
    char query_copy[1024];
    strncpy(query_copy, query, sizeof(query_copy));

    // Convert the query to uppercase
    for (int i = 0; query_copy[i]; i++) {
        query_copy[i] = toupper(query_copy[i]);
    }

    // Check the type of SQL command
    if (strncmp(query_copy, "INSERT INTO", 11) == 0) {
        handle_insert(query);
    } else if (strncmp(query_copy, "SELECT * FROM", 14) == 0) {
        handle_select(query);
    } else if (strncmp(query_copy, "DELETE FROM", 11) == 0) {
        handle_delete(query);
    } else {
        printf("Unknown SQL command.\n");
    }
}
