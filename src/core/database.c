#include <stdio.h>
#include <stdlib.h>
#include "database.h"

// Function to write a record to the file
void write_record(FILE *file, Record *rec) {
    fwrite(rec, sizeof(Record), 1, file);
}

// Function to read a record from the file at a given offset
void read_record(FILE *file, long offset, Record *rec) {
    fseek(file, offset * sizeof(Record), SEEK_SET);
    fread(rec, sizeof(Record), 1, file);
}
