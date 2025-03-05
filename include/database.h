#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>

#define MAX_NAME_LENGTH 100  // Limit for the name field

// Record structure (fixed size)
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    int is_deleted;
} Record;


void insert_user(const char *filename, Record *rec);
void select_users(const char *filename);


// WAL functions 
void delete_user(const char *filename , int id);
void log_delete(int id);
int is_deleted(int id);


// VACUUM cleanup
void vacuum_database(const char *filename);


#endif  // DATABASE_H
