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

#include <time.h>

// Define the structure for a queue node
typedef struct queue_node {
    int id;
    time_t timestamp;
    struct queue_node* next;
} queue_node;

// Define the structure for the queue
typedef struct queue {
    queue_node* front;
    queue_node* rear;
    int size;
} queue;

// Function to create a new queue
queue* create_queue();

// Function to create a new node
queue_node* create_qnode(int id);

// Function to enqueue an element into the queue
void enqueue(queue* q, int id);

// Function to dequeue an element from the queue and returns id
int dequeue(queue* q);

// Function to get the size of the queue
int get_queuesize(queue* q);

// Function to display all elements in the queue
void print_queue(queue* q);

// Function to get front element of queue without dequeue
queue_node* get_front_qitem(queue* q);
