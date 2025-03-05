# Database Implementation 




### Define the record struct 
```
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Record;
```

### Defining the files holding our code 
* /src/database.c
This will contain the functions to interact with the database (write and read records).

* /src/database.h
The header file where you declare the functions, structs, and constants to be used in database.c and main.c.


### How to run your code 
gcc src/main.c src/database.c -o my_database_project
./my_database_project

you can do it using makefile : 
make // run compile the Makefile
make clean // remove and clean the objects





### Basic Operations

The project initially starts with three basic files : 

```
/mini_db_project
│
├── src/
│   ├── database.c           # Contains file operations (open, read, write).
│   ├── insert_user.c        # Contains the insert function.
│   ├── read_users.c         # Contains the read function.
│   └── main.c               # Main entry point to test everything.
│
├── include/
│   └── database.h           # Header file with struct and function prototypes.
│
└── Makefile                 # To easily compile the project.

```

