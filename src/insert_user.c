// #include "database.h"
// #include <stdio.h> 

// void insert_user(const char *filename, Record *rec) {
//     FILE *file = fopen(filename, "ab");  
//     if (file == NULL) {
//         perror("Failed to open file");
//         return;
//     }

//     // takes a pointer to the user struct and it's size and write one record of it.
//     fwrite(rec, sizeof(User), 1, file);  
//     fclose(file);
// }
