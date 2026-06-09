#ifdef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node;
struct Node* list_create_head(int value);
struct Node* list_push_back(struct Node* node,int value); // Go to the last node and add
void list_pop(struct Node* node); //just delete
void free_list(struct Node* node); //Free/delete entire list
int get_list_length(struct Node* head);
void print_list(struct Node* start); // print every node starting on start
void list_free(struct Node* head, struct Node* node); // Free/Remove Node, if not last -> organize list
void swap_node(struct Node* node1, struct Node* node2); //this swap entirely(pointer and data), usa only if you really need
void swap_node_data(struct Node* node1, struct Node* node2); // this only swap data, faster
int list_compare_data(struct Node* node1, struct Node* node2); //equal = 0, n1 > n2 = 1, n1 < n2 = -1
struct Node* list_get_middle(struct Node* startingNode);
void list_bubble_sort(struct Node* head);

#endif