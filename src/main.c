#include <stdio.h>
#include "database.h"

int main() {
    Record rec1 = {1, "Alice", 30};
    Record rec2 = {2, "Bob", 25};

    insert_user("bin/database.dat", &rec1);
    insert_user("bin/database.dat", &rec2);

    printf("\nCurrent Users:\n");
    select_users("bin/database.dat");

    printf("\nDeleting Bob...\n");
    delete_user("bin/database.dat", 2);

    printf("\nUsers after delete (not vacuumed):\n");
    select_users("bin/database.dat");

    printf("\nRunning VACUUM...\n");
    vacuum_database("bin/database.dat");

    printf("\nUsers after vacuum:\n");
    select_users("bin/database.dat");

    return 0;
}
