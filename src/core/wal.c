#include <stdio.h>
#include "database.h"

// Log a DELETE request into deletion.log
void log_delete(int id) {
    FILE *log_file = fopen("bin/deletion.log", "a");
    if (!log_file) {
        perror("Error opening deletion log");
        return;
    }
    fprintf(log_file, "%d\n", id);
    fclose(log_file);
}

// Check if an ID is marked as deleted
int is_deleted(int id) {
    FILE *log_file = fopen("bin/deletion.log", "r");
    if (!log_file) return 0;

    int deleted_id;
    while (fscanf(log_file, "%d", &deleted_id) == 1) {
        if (deleted_id == id) {
            fclose(log_file);
            return 1;
        }
    }

    fclose(log_file);
    return 0;
}
