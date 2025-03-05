#include "database.h"
#include <stdio.h> 

void insert_user(const char *filename, User *user) {
    FILE *file = fopen(filename, "ab");  
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    // takes a pointer to the user struct and it's size and write one record of it.
    fwrite(user, sizeof(User), 1, file);  
    fclose(file);
}
