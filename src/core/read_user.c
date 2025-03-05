#include <stdio.h>
#include "database.h"

void select_users(const char *filename) {
    FILE *file = fopen(filename, "rb");  // Read mode
    if (!file) {
        perror("Error opening file");
        return;
    }

    Record rec;
    while (fread(&rec, sizeof(Record), 1, file)) {
        if (!is_deleted(rec.id)) {  // Check if the record is marked as deleted
            printf("ID: %d, Name: %s, Age: %d\n", rec.id, rec.name, rec.age);
        }
    }

    fclose(file);
}
