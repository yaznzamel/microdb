// /src/database.h
#ifndef DATABASE_H
#define DATABASE_H



#define MAX_NAME_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Record;


#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    int id;                // Primary Key
    char name[MAX_NAME_LENGTH];  // User name
    int age;               // User age
} User;


void write_record(FILE *file, Record *rec);
void read_record(FILE *file, long offset, Record *rec);


// Function prototypes for user operations
void insert_user(const char *filename, Record *rec);
void select_users(const char *filename);
void delete_user(const char *filename, int id);

#endif // DATABASE_H




