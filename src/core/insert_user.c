#include <stdio.h>
#include <stdlib.h>
#include "database.h"

// Function to insert a user record into the database file
void insert_user(const char *filename, Record *rec) {
    FILE *file = fopen(filename, "ab");  
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    write_record(file, rec);
    fclose(file);
    printf("Inserted record: ID=%d, Name=%s, Age=%d\n", rec->id, rec->name, rec->age);
}
