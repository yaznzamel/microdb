#include <stdio.h>
#include "database.h"


void delete_user(const char *filename , int id){
    log_delete(id);
    printf("DELETE request logged for ID %d.\n", id);

}