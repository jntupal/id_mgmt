/**
    Copyright [2024] [Yogendra Pal, Email: jntupal@gmail.com]

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the binary search tree
typedef struct node {
    int hash_value;
    int id;
    struct node* left;
    struct node* right;
} node;

// Function to create a new node
node* create_node(int hash_value, int id);

// Function to insert a node into the BST
node* insert_node(node* root, char* data, int* id, int* hash_val);

// Function to delete node from BST
node* delete_node(node* root, int hash_value);

// Function to print the binary search tree in inorder traversal
void print_tree(node* root);

// Function to calculate the hash value using the djb2 algorithm
int hash_func(char* str);

// Structure to represent ID and data. This will be used in the
// query and delete operation of ID
typedef struct id_info {
    int id;
    char* data;
    int hash_value;
    struct id_info* left;
    struct id_info* right;
} id_info;

// Function to create new id_info
id_info* create_idinfo(int id, int hash_value, char* data);

// Function to insert id_info into BST. Key is id
id_info* insert_idinfo(id_info* root, int id, int hash_value, char* data);

// Function to delete id_info from BST
id_info* delete_id_info(id_info* root, int id);

// Function to query and get the data back from id
id_info* lookup_idinfo(id_info* root, int id);

// Function to print ID/DATA BST tree in inorder traversal
void print_tree2(id_info* root);
