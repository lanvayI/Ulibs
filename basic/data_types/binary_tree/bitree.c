#include <stdlib.h>
#include <stdio.h>
#include "bitree.h"

int tree_size = 0;
int Get_Node_Quantity(){
	return tree_size;
}

Tnode* CreateHead(int value){
	Tnode* head = NULL;
	head = (Tnode*)malloc(sizeof(Tnode));
	if(!head){
		puts("Head Allocation Failed");
		return NULL;
	}
	head -> data = value;
	head -> left = NULL;
	head -> right = NULL;
	head -> parent = NULL;

	tree_size++;
	return head;
}

void FreeList(Tnode** phead){
	Tnode* temp = *phead;
	Tnode* temp2 = *phead;
	//ir para a extrema esquerda e começar a free laa e ir subindo
	while(temp -> left != NULL){temp = temp->left;} // temp agora é penultimo esquerdo possivel do lado  esquerdo
	//agora é ir subindo e apagando tudo
	while(temp2->left != NULL){
		Tnode* pai = temp->parent;
		temp -> left = NULL;
		temp -> right = NULL;
		
		free(temp->left);
		free(temp->right);
		free(temp);
		temp = pai;
	}
	//agora só repetir para a direita
	while(temp -> right != NULL){temp = temp->right;} // temp agora é penultimo esquerdo possivel do lado  esquerdo
	//agora é ir subindo e apagando tudo
	while(temp2->right != NULL){
		Tnode* pai = temp->parent;
		temp -> left = NULL;
		temp -> right = NULL;
		
		free(temp->left);
		free(temp->right);
		free(temp);
		temp = pai;
	}
	
	//por fim o head vai tbm
	tree_size = 0;
	free(*phead);
	*phead = NULL;
}

Tnode* PushBack(Tnode* startPos, int value){
	Tnode* this = NULL;
	this = (Tnode*)malloc(sizeof(Tnode));
	if(!this){
		puts("Pushback Allocation Failed");
		return NULL;
	}
	this->data = value;
	this->left = NULL; this->right = NULL;
	this->parent = startPos;
	// aqui vai ter logica para determinar se vai ser left ou right
	//por enquanto se o valor for maior ir para a direita
	if(value % 2 == 0){
		startPos->right = this;
	}else{startPos->left = this;}
	tree_size++;
	return this;
}

void prS(int times){ //just print spaces
	for(int i=0;i<times;i++){
		printf(" ");
	}
}

int check(Tnode* now){ // 0: ALL NULL
	if(now->left == NULL && now->right == NULL){return 0;}
	if(now->left != NULL && now->right == NULL){return -1;}
	if(now->left == NULL && now->right != NULL){return 1;}
	printf("\n, uh, error on int check(), bitree. Well, how idk");
	return 0;
}

