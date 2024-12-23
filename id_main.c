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

#include "queue.h"
#include "id_mgmt.h"

#define ID_STALE_TIMEOUT 5

int main()
{
    node* root = NULL;
    id_info* root_ii = NULL;
    char input[100];

    printf("\nUSAGE\n");
    printf("\nEnter option: 1 for Creating ID for string (or 4 to quit): ");
    printf("\nEnter option: 2 for Querying ID (or 4 to quit): ");
    printf("\nEnter option: 3 to  Delete ID (or 4 to quit): ");
    printf("\nEnter option: 5 to  print BST (or 4 to quit): ");

    // Init the queue
    queue* q = create_queue();

    while (1) {
        int _option = 4, _id;
        id_info *ii = NULL;
        int hash_val;
        queue_node* qtemp = NULL;

        printf("\nEnter option: (or 4 to quit): ");
        scanf("%d", &_option);

        // Handle the options
        if (_option == 1) {
            printf("\nEnter a string: ");
            scanf("%s", input);

            // Use id from previous allocation if available through
            // delete_id operation and passed the timeout period of
            // ID_STALE_TIMEOUT = 5sec
            _id = 0;
            qtemp = get_front_qitem(q);
            if (qtemp != NULL) {
                time_t now = time(NULL);
                double tdiff = difftime(now, qtemp->timestamp); 
                if (tdiff >= ID_STALE_TIMEOUT) {
                    _id = dequeue(q);
                }
            }
            
            root = insert_node(root, input, &_id, &hash_val);
            printf("ID: %d", _id);
            root_ii = insert_idinfo(root_ii, _id, hash_val, input); 
            continue;
        } else if (_option == 2) {
            printf("\nEnter Query ID: ");
            scanf("%d", &_id);

            ii = lookup_idinfo(root_ii, _id);
            if (ii) {
                printf("ID data: %s\n", ii->data);
            } else {
                printf("ID Not found\n");
            }
            continue;
        } else if (_option == 3) {
            printf("\nEnter Delete ID: ");
            scanf("%d", &_id);

            ii = lookup_idinfo(root_ii, _id);
            if (ii) {
                int _hv;
                _hv = ii->hash_value;
                root_ii = delete_id_info(root_ii, ii->id);
                root    = delete_node(root, _hv);
                // Recycle the id for later use
                enqueue(q, _id);
            } else {
                printf("ID Not found\n");
            }
            continue;
        } else if (_option == 4) {
            free(q);
            break;
        } else if (_option == 5) {
            if (root != NULL) {
                printf("\nHASH/ID, Binary Search Tree:\n");
                print_tree(root);
            }
            if (root_ii != NULL) {
                printf("\nID/DATA, Binary Search Tree:\n");
                print_tree2(root_ii);
            }
            continue;
        }
    }

    return 0;
}
