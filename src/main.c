// /src/main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "sql_interpreter.h"



int old(){
     // Open the file for writing
    FILE *file = fopen("bin/database.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("The file craetedd %p \n" ,file);

    // Create some records to add
    Record rec1 = {1, "Alice", 30};
    Record rec2 = {2, "Bob", 25};

    // Write the records to the file
    write_record(file, &rec1);
    write_record(file, &rec2);

    fclose(file);

    // Now let's read the records from the file
    file = fopen("bin/database.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    Record readRec;
    read_record(file, 0, &readRec);  // Read first record
    printf("ID: %d, Name: %s, Age: %d\n", readRec.id, readRec.name, readRec.age);

    read_record(file, 1, &readRec);  // Read second record
    printf("ID: %d, Name: %s, Age: %d\n", readRec.id, readRec.name, readRec.age);

    fclose(file);

    return 0;

}


#define MAX_QUERY_LEN 1024

int main() {
    char query[MAX_QUERY_LEN];
    
    printf("Welcome to the simple database. Type 'EXIT' to quit.\n");

    // Interactive loop to accept user input
    while (1) {
        // Prompt user for a query
        printf("\nEnter SQL query: ");
        
        // Read the input query from user
        if (fgets(query, sizeof(query), stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        // Remove trailing newline character from fgets
        query[strcspn(query, "\n")] = 0;

        // Exit if user types "EXIT"
        if (strcmp(query, "EXIT") == 0) {
            printf("Exiting the database.\n");
            break;
        }

        // Process the SQL query
        sql_interpreter(query);
    }

    return 0;
}




