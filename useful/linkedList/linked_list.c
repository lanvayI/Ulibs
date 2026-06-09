#include <stdlib.h>
#include "linked_list.h"

struct Node{
	int data;
	struct Node* next;
};

struct Node* list_create_head(int value){
	struct Node* head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node*));
	if(!head){
		printf("Head Allocation Failed");
		return NULL;
	}
	
	head -> data = value; head -> next = NULL;
	return head;
}

struct Node* list_push_back(struct Node* node, int value){ 
	struct Node* temp;
	temp = node;
	
	while(temp -> next != NULL){
		temp = temp->next;
	}
	
	struct Node* newNode = NULL;
	newNode = (struct Node*)malloc((sizeof(struct Node)));
	if(!newNode){
		printf("Head Allocation Failed");
		return NULL;
	}
	
	temp -> next = newNode;
	newNode-> next = NULL;
	newNode-> data = value;
	return newNode;
}


void list_pop(struct Node* node){
	if(node -> next == NULL){
		free(node);
		node = NULL;
		return;
	}else{printf("Nao estourado!\n");}

	//@@@@@
	struct Node* temp = node;
	while(temp->next != NULL){
		temp = temp->next;
	}
	free(temp);
	temp = NULL;
}

void free_list(struct Node* node){
	struct Node* temp = node;
	while(temp != NULL){
		struct Node* next = temp->next;
		free(temp);
		temp=next;
	}
}

int get_list_length(struct Node* head){
	if(head == NULL || !head){return 0;}
	struct Node* temp = head;
	int i=1;
	while(temp->next != NULL){
		temp = temp->next;
		i++;
	}
	return i;
}

void print_list(struct Node* start){
	if(start == NULL || !start){return;}
	struct Node* temp = start;
	int i = 0;
	while(temp != NULL){
		printf("Node %i: %i / ",i,temp->data);
		temp = temp->next;
		i++;
	}
}

void list_free(struct Node* head, struct Node* node){
	if(head==node){printf("Can't free head! cuz i am lazy\n"); return;}
	
	if(node->next == NULL){
		struct Node* temp = head;
		while(temp->next->next != NULL){temp=temp->next;}
		temp->next=NULL;
		list_pop(node);
		return;
	}
		
	struct Node* temp = head;
	while(temp->next != node){temp = temp->next;}
	
	temp->next = node->next;
	node->next = NULL;
	list_pop(node);

}

void swap_node(struct Node* head, struct Node* node1, struct Node* node2){
	if(head == node1 || head == node2){printf("nada de mudar head n\n");return;}
	if(node1==node2){printf("vai mudar oq");return;}
	
	struct Node* temp = head;
	struct Node* tempbefore1;
	struct Node* tempbefore2;
	
	if(temp->next == node1){tempbefore1=temp;}
	while(temp->next != node2){
		if(temp->next == node1){tempbefore1=temp;};
		temp=temp->next;
	}
	tempbefore2=temp;
	
	struct Node* node2next = node2->next;
	
	tempbefore1->next = node2;
	tempbefore2->next = node1;
	
	node2->next = node1->next;
	node1->next = node2next;
}

void swap_node_data(struct Node* node1, struct Node* node2){
	int temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}


int list_compare_data(struct Node* node1, struct Node* node2){
	if(node1->data == node2->data){return 0;}
	if(node1->data > node2->data){return 1;}
	if(node1->data < node2->data){return -1;}
	return 0;
}

struct Node* list_get_middle(struct Node* startingNode){
	struct Node* slow = startingNode;
	struct Node* fast = slow;
	
	while(fast!=NULL && fast->next !=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

void list_bubble_sort(struct Node* head){
    int size = get_list_length(head);

    for(int j = 0; j < size - 1; j++){
        int madeSmth = 0;
        struct Node* temp = head;

        for(int i = 0; i < size - j - 1; i++){
            if(temp->next == NULL) break;

            if(temp->data > temp->next->data){
                int tmp = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tmp;

                madeSmth = 1;
            }

            temp = temp->next;
        }

        if(!madeSmth) return;
    }
}
