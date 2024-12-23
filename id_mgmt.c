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

#include "id_mgmt.h"

static int global_id = 1;

// Function to create a new node
node* create_node(int hash_value, int id) 
{
    node* new_node = (node*) malloc(sizeof(node));
    if (!new_node) {
        printf("Memory error\n");
        return NULL;
    }
    new_node->hash_value = hash_value;
    new_node->id = id;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to calculate the hash value using the djb2 algorithm
int hash_func(char* str) 
{
    int hash_value = 5381;
    int c;
    while ((c = *str++)) {
        hash_value = ((hash_value << 5) + hash_value) + c;
    }
    return hash_value;
}

// Function to insert a node into the binary search tree
node* insert_node(node* root, char* data, int* id, int* hash_val)
{
    int hash_value = hash_func(data);
    if (root == NULL) {
        int _id;
        if (*id == 0) {
            _id = global_id;
            global_id++;
            *id = _id;
        } else {
            // Use the previous allocated id from id space.
            _id = *id;
        }

        *hash_val = hash_value;
        return create_node(hash_value, _id);
    }
    if (hash_value < root->hash_value) {
        root->left = insert_node(root->left, data, id, hash_val);
    } else if (hash_value > root->hash_value) {
        root->right = insert_node(root->right, data, id, hash_val);
    }
    return root;
}

// Function to print the binary search tree in inorder traversal
void print_tree(node* root)
{
    if (root) {
        print_tree(root->left);
        printf("Hash Value: %d, ID: %d\n", root->hash_value, root->id);
        print_tree(root->right);
    }
}

// Function to free the node
void free_node(node* n)
{
    if (n) {
        free(n);
        n = NULL;
    }
}

// Function to find minimum node in a BST
node* find_min(node* root)
{
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Function to delete node from BST
node* delete_node(node* root, int hash_value)
{
    if (root == NULL) {
        return root; // Node not found
    }

    // Traverse the tree
    if (hash_value < root->hash_value) {
        root->left = delete_node(root->left, hash_value);
    } else if (hash_value > root->hash_value) {
        root->right = delete_node(root->right, hash_value);
    } else {
        // Node found
        if (root->left == NULL) {
            // Node with only right child or no child
            node* temp = root->right;
            free_node(root);
            return temp;
        } else if (root->right == NULL) {
            // Node with only left child
            node* temp = root->left;
            free_node(root);
            return temp;
        }

        // Node with two children: Get the in-order successor
        node* temp = find_min(root->right);

        // Copy the successor's data to the current node
        root->hash_value = temp->hash_value;
        root->id = temp->id;

        // Delete the in-order successor
        root->right = delete_node(root->right, temp->hash_value);
    }

    return root;
}

// Function to print ID/DATA BST tree in inorder traversal
void print_tree2(id_info* root)
{
    if (root) {
        print_tree2(root->left);
        printf("Hash Value: %d, ID: %d, Data: %s\n", 
               root->hash_value, root->id, root->data);
        print_tree2(root->right);
    }
}

// Function to create new id_info
id_info* create_idinfo(int id, int hash_value, char* data)
{
    id_info* new_ii = (id_info* ) malloc(sizeof(id_info));
    if (!new_ii) {
        printf("Memory error\n");
        return NULL;
    }

    new_ii->id = id;
    new_ii->hash_value = hash_value;
    new_ii->data = strdup(data);
    new_ii->left = new_ii->right = NULL;
    return new_ii;
}

// Function to insert id_info into BST. Key is id
id_info* insert_idinfo(id_info* root, int id, int hash_value, char* data)
{
    if (root == NULL) {
        return create_idinfo(id, hash_value, data);
    }
    if (id < root->id) {
        root->left = insert_idinfo(root->left, id, hash_value, data);
    } else if (id > root->id) {
        root->right = insert_idinfo(root->right, id, hash_value, data);
    }
    return root;
}


// Function to query and get the data back from id
id_info* lookup_idinfo(id_info* root, int id)
{
    if (root == NULL) {
        return root;
    }

    if (root->id == id) {
        return root;
    } else if (id < root->id) {
        return lookup_idinfo(root->left, id);
    } else if (id > root->id) {
        return lookup_idinfo(root->right, id);
    } else {
        return NULL;
    }
}

// Function to free a single id_info node
void free_idinfo_node(id_info* node)
{
    if (node) {
        free(node->data);
        free(node);
        node = NULL;
    }
}

// Function to find minimum node in a subtree
id_info* find_min_idinfo(id_info* root)
{
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Function to delete id_info from BST
id_info* delete_id_info(id_info* root, int id)
{
    if (root == NULL) {
        return root; // Node not found
    }

    // Traverse the tree
    if (id < root->id) {
        root->left = delete_id_info(root->left, id);
    } else if (id > root->id) {
        root->right = delete_id_info(root->right, id);
    } else {
        // Node found
        if (root->left == NULL) {
            // Node with only right child or no child
            id_info* temp = root->right;
            free_idinfo_node(root);
            return temp;
        } else if (root->right == NULL) {
            // Node with only left child
            id_info* temp = root->left;
            free_idinfo_node(root);
            return temp;
        }

        // Node with two children: Get the in-order successor
        id_info* temp = find_min_idinfo(root->right);

        // Copy the successor's data to the current node
        root->id = temp->id;
        free(root->data);
        root->data = strdup(temp->data);
        root->hash_value = temp->hash_value;

        // Delete the in-order successor
        root->right = delete_id_info(root->right, temp->id);
    }

    return root;
}
