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
#include <stdbool.h>
#include <time.h>

#include "queue.h"

// Function to create a new queue
queue* create_queue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to create a new node
queue_node* create_qnode(int id)
{
    queue_node* qnode = (queue_node*)malloc(sizeof(queue_node));
    qnode->id = id;
    qnode->timestamp = time(NULL);
    qnode->next = NULL;
    return qnode;
}

// Function to enqueue an element into the queue
void enqueue(queue* q, int id)
{
    queue_node* qnode = create_qnode(id);
    if (q->rear == NULL) {
        q->front = qnode;
        q->rear = qnode;
    } else {
        q->rear->next = qnode;
        q->rear = qnode;
    }
    q->size++;
    printf("Enqueued: ID = %d, Timestamp = %ld\n", id, qnode->timestamp);
}

// Function to dequeue an element from the queue and returns id
int dequeue(queue* q)
{
    int id;
    time_t timestamp;
    queue_node* temp;

    if (q->front == NULL) {
        printf("queue is empty, cannot dequeue.\n");
        return -1;
    }
    temp = q->front;
    id = temp->id;
    timestamp = temp->timestamp;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    printf("Dequeued: ID = %d, Timestamp = %ld\n", id, timestamp);
    return id;
}

// Function to get the size of the queue
int get_queuesize(queue* q)
{
    return q->size;
}

// Function to display all elements in the queue
void print_queue(queue* q)
{
    if (q->front == NULL) {
        printf("queue is empty.\n");
        return;
    }

    queue_node* temp = q->front;
    printf("queue elements: \n");
    while (temp != NULL) {
        printf("ID = %d, Timestamp = %ld\n", temp->id, temp->timestamp);
        temp = temp->next;
    }
    printf("\n");
}

// Function to get front element of queue without dequeue
queue_node* get_front_qitem(queue* q)
{
    if (q->front == NULL) {
        return NULL;
    }
    return q->front;
}

