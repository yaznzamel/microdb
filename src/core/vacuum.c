#include <stdio.h>
#include "database.h"

void vacuum_database(const char *filename) {
    FILE *file = fopen(filename, "rb");  // Read old database
    if (!file) {
        perror("Error opening database file");
        return;
    }

    FILE *temp_file = fopen("bin/temp.dat", "wb");  // New database
    if (!temp_file) {
        perror("Error opening temp file");
        fclose(file);
        return;
    }

    Record rec;
    while (fread(&rec, sizeof(Record), 1, file)) {
        if (!is_deleted(rec.id)) {  // Copy only non-deleted records
            fwrite(&rec, sizeof(Record), 1, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(filename);  // Remove old database
    rename("bin/temp.dat", filename);  // Replace with cleaned version

    // Clear deletion log
    FILE *log_file = fopen("bin/deletion.log", "w");
    if (log_file) fclose(log_file);

    printf("Database vacuumed: All deleted records permanently removed.\n");
}
