// #include "database.h"
// #include <stdio.h> 

// void read_users(const char *filename) {
//     FILE *file = fopen(filename, "rb");  // Open file in read-binary mode
//     if (file == NULL) {
//         perror("Failed to open file");
//         return;
//     }

//     User user;
//     while (fread(&user, sizeof(User), 1, file)) {  // Read each user from the file
//         printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
//     }

//     fclose(file);
// }
