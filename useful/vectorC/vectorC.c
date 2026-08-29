#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/vectorC.h"
#define INCREASE_SIZE 5

vector** v_array = NULL;
int v_size = 0, v_items = 0;

vector* Vector_Init(size_t esize){
	vector* self = malloc(sizeof(vector));
	if(self == NULL){return NULL; puts("alloc on init failed, vector pointer step\n");}
	
	void* tmp = malloc(esize);
	if(tmp==NULL){return NULL;puts("alloc on init failed, data pointer step\n");}
	
	self->data = tmp;	
	self->element_size = esize;
	self->size = 1;
	self->nItems = 0;
	add_to_collector(self);
	return self;
}

int EmplaceBack(vector* list, void* src){
	//checar se tem espaço
	if(list->size == list->nItems){
		int newSize = list->size + INCREASE_SIZE;
	//allocar memoria e aumentar size
		void *tmp = realloc(list->data, newSize * list->element_size);	
		if(tmp == NULL){puts("vectorC : realloc failed");return 0;}	
	list->data = tmp;
	list->size = newSize;
	}
	memcpy((unsigned char*)list->data+(list->element_size*list->nItems),src,list->element_size);	
	list->nItems++;
	#ifdef VECTOR_DEBUG
	puts("vectorC.c : emplaceBack : added");
	#endif
	return 1;
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
	printf("size: %d, nItems: %d, e size: %lld\n ",lista->size,lista->nItems,lista->element_size);
}

unsigned char* IAt(vector* lista,int index, size_t esize){
	return (unsigned char*)lista->data + (esize*index);
}//Item At Index
 
int remove_at(vector *list, int index)
{
    if (index < 0 || index >= list->nItems){
		#ifdef VECTOR_DEBUG 
		puts("vectorc : remove_at : cant acess, out of bounds"); 
		#endif
        return 0;}
	
    if (index < list->nItems - 1)
    {
        memmove(
            (char *)list->data + index * list->element_size,
            (char *)list->data + (index + 1) * list->element_size,
            (list->nItems - index - 1) * list->element_size
        );
    }

    list->nItems--;

    memset(
        (char *)list->data + list->nItems * list->element_size,
        0,
        list->element_size
    );

    return 1;
}

//Garbage functions

void add_to_collector(vector* v){
	if(v_array==NULL){
		v_array = (vector**)malloc(sizeof(vector*));
		if(v_array==NULL){puts("add_to_collector : failed to alocate v_array"); return;}
		v_size++;
		#ifdef DEBUG
		puts("add_to_collector : v_array alocated, sucess");
		#endif
	}
	if(v_items + 1 > v_size){
		vector** tmp = (vector**)realloc(v_array,sizeof(vector*)*(v_size+1));
		if(tmp==NULL){puts("add_to_collector : failed to realloc"); return;}
		v_array = tmp;
		v_size++;
	}
	v_array[v_items] = v;
	v_items++;
	#ifdef DEBUG
	puts("add_to_collector : sucess");
	#endif
}

void final_clean(){
	#ifdef DEBUG
	printf("final clean: start, vectors: %d, v_array size %d\n",v_items,v_size);
	#endif
	for(int i=0; i<v_size;i++){
		if(v_array[i] == NULL){continue;}
		#ifdef DEBUG_VECTOR_CLEAN
		printf("final clean: vector %d clean -> nitems: %d, size %d\n",i,v_array[i]->nItems,v_array[i]->size);
		#endif

		free(v_array[i]->data);
		v_array[i]->data = NULL;
		free(v_array[i]);
		v_array[i] = NULL;
	}
	free(v_array);
	v_array = NULL;
	#ifdef DEBUG
	puts("final_clean : sucess");
	#endif
}