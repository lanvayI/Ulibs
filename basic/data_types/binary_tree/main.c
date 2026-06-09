#include <stdio.h>
#include "bitree.h"
#include "bitree.c"
#include "include/raylib.h"
#define HEAD_X 320
#define HEAD_Y 60
void drawLR(Tnode* node,int xpos, int ypos,int xset, int yset);
int checarSeTaNaLista(int* lista, int aChecar,int size);

int main(void){
	Tnode* head = CreateHead(1);
	Tnode* n1 = PushBack(head,2);
	Tnode* n2 = PushBack(head,3);
	PushBack(n1,4);
	PushBack(n2,6);
	//PushBack(n2,5);
	Tnode* temp = head;
	
	InitWindow(640,480,"ok");
	SetTargetFPS(60);
	int layer=0;
	int canStop = Get_Node_Quantity()-1;
	int compare[Get_Node_Quantity()-1]; int index = 0;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		
		//DrawCircle(HEAD_X,HEAD_Y,20,GRAY);
		//DrawText(TextFormat("%i",head->data),HEAD_X-5,HEAD_Y-15,30,BLACK); // -5, -15
		//drawLR(head,HEAD_X,HEAD_Y,50*2,50*2);
		
		while(canStop!=0){
			//se não tem ambos lados e ja desceu, subir
			if(!!checarSeTaNaLista(compare,temp->left->data,Get_Node_Quantity()) && !checarSeTaNaLista(compare,temp->right->data,Get_Node_Quantity()) && layer > 0){
				temp = temp->parent;
				layer--;
				puts("1");
				continue;
			}
			// ir pra esq e se n tiver esq e tiver dir vai dir
			if(temp->left && !checarSeTaNaLista(compare,temp->left->data,Get_Node_Quantity())){
				compare[index++] = temp->left->data;
				temp = temp->left; 
				layer++;
				canStop--;
				puts("2");
				continue;
			}
			if(temp->right && !checarSeTaNaLista(compare,temp->right->data,Get_Node_Quantity())){
				compare[index++] = temp->right->data;
				temp = temp->right; 
				layer++;
				canStop--;
				puts("3");
				continue;
			}
		}
		
		EndDrawing();
	}
	
	CloseWindow();
	
	for(int i=0;i<Get_Node_Quantity();i++){
		printf("%i ",compare[i]);
	}
	FreeList(&head);
	return 0;
}

void drawLR(Tnode* node,int xpos, int ypos,int xset, int yset){
	Tnode* temp = node;
	int right = xpos + xset;
	xset=xpos-xset;
	yset+=ypos;
	if(temp->left){
		DrawLine(xset,yset,xpos,ypos,BLACK);
		DrawCircle(xset,yset,20,GRAY);
		DrawText(TextFormat("%i",temp->left->data),xset-5,yset-15,30,BLACK);
	}
	if(temp->right){
		DrawLine(right,yset,xpos,ypos,BLACK);
		DrawCircle(right,yset,20,GRAY);
		DrawText(TextFormat("%i",temp->right->data),right-5,yset-15,30,BLACK);
	}
}

int checarSeTaNaLista(int* lista, int aChecar,int size){
	printf(" achecar:%i ",aChecar);
	for(int i=0;i<size;i++){
		if(aChecar == lista[i]){return 1;}else{return 0;}
	}
	return 0;
}

/*all:
	gcc main.c -o Game.exe -O2 -Wall -Wno-missing-braces -Wnarrowing -I ../include -L ../lib -lraylib -lopengl32 -lgdi32 -lwinmm
	./Game.exe
	
*/