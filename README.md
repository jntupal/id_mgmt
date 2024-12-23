# id_mgmt
Integer ID management library

############### License ################################
This project is under Apache license 2.0

############### ID Management Library ##################

### Introduction ###
    This library provides user with integer id whose values
    starts from 1 to 2^32-1 for any given string as input.

### Operations supported ###
    Various operations supported by this library is below:

    create_id("foobar"), ID = <1>
    create_id("foo"),    ID = <2>
    create_id("fo"),     ID = <3>
    create_id("f"),      ID = <4>
    ...
    query_id(1), data = "foobar"
    query_id(2), data = "foo"
    query_id(3), data = "fo"
    query_id(4), data = "f"

    delete_id(1)
    delete_id(2)

############### id_mgmt ###############################

### Folder files: <id_mgmt> ###

### Source files:
    id_main.c
    id_mgmt.c
    id_mgmt.h
    queue.c
    queue.h
    Makefile

### Building the id_mgmt library ### 
    1. cd id_mgmt
    2. make
    3. sample output.
    -rw-rw-r-- 1 ypal ypal  2175 Dec 23 00:48 id_main.c
    -rw-rw-r-- 1 ypal ypal  8416 Dec 23 15:39 id_main.o
    -rw-rw-r-- 1 ypal ypal  6048 Dec 23 00:48 id_mgmt.c
    -rw-rw-r-- 1 ypal ypal  1425 Dec 23 00:40 id_mgmt.h
    -rw-rw-r-- 1 ypal ypal 12728 Dec 23 15:39 id_mgmt.o
    -rwxrwxr-x 1 ypal ypal 22232 Dec 23 15:39 id_program*
    -rw-rw-r-- 1 ypal ypal 13094 Dec 23 15:39 libid_mgmt.a
    -rw-rw-r-- 1 ypal ypal   691 Dec 23 12:09 Makefile
    -rw-rw-r-- 1 ypal ypal  1102 Dec 23 16:29 README.md

### Output of build target ###
    1. libid_mgmt.a
    2. id_program // This is test program to exercise libid_mgmt.a

### Usage ###

    id_mgmt$ ./id_program

    USAGE

    Enter option: 1 for Creating ID for string (or 4 to quit): 
    Enter option: 2 for Querying ID (or 4 to quit): 
    Enter option: 3 to  Delete ID (or 4 to quit): 
    Enter option: 5 to  print BST (or 4 to quit): 
    Enter option: (or 4 to quit): 

