// /src/database.c
#include <stdio.h>
#include <stdlib.h>
#include "database.h"


void write_record(FILE *file, Record *rec) {
    fwrite(rec, sizeof(Record), 1, file);
}


void read_record(FILE *file, long offset, Record *rec) {
    fseek(file, offset * sizeof(Record), SEEK_SET); // Move the file pointer to the correct record's location
    fread(rec, sizeof(Record), 1, file); // Read the record from the file
}



