#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vectorC.h"
#define INCREASE_SIZE 5

vector* Vector_Init(size_t esize){
	vector* self = malloc(sizeof(vector));
	if(self == NULL){return NULL; puts("alloc on init failed, vector pointer step\n");}
	
	void* tmp = malloc(esize);
	if(tmp==NULL){return NULL;puts("alloc on init failed, data pointer step\n");}
	
	self->data = tmp;	
	self->element_size = esize;
	self->size = 1;
	self->nItems = 0;
	return self;
}

void EmplaceBack(vector* list, void* src){
	//checar se tem espaço
	if(list->size == list->nItems){
		int newSize = list->size + INCREASE_SIZE;
	//allocar memoria e aumentar size
		void *tmp = realloc(list->data, newSize * list->element_size);	
		if(tmp == NULL){puts("realloc failed");return;}	
	list->data = tmp;
	list->size = newSize;
	}
	memcpy((unsigned char*)list->data+(list->element_size*list->nItems),src,list->element_size);	
	list->nItems++;
	//aumentar nitems se sucesso
}

void PopBack(vector *list){
	memset((unsigned char*)list->data +(list->element_size * (list->nItems-1)) ,0,list->element_size);
//	list->data[list->nItems-1] = 0;
	list->nItems--;
	//diminuir tamanho
	if(list->nItems <= list->size/2){ //tem metade sobrando em 0
		int newSize = list->nItems;
		void *tmp = realloc(list->data, newSize * list->element_size);
		if(tmp == NULL){puts("realooc failed"); return;}

		list->data = tmp;
		list->size = newSize;	
	}
}

void print_info(vector* lista){
	printf("\n size: %d, nItems: %d, e size: %lld: ",lista->size,lista->nItems,lista->element_size);
}

unsigned char* IAt(vector* lista,int index, size_t esize){
	return (unsigned char*)lista->data + (esize*index);
}//Item At Index
