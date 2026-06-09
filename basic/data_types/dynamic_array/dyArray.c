#include <stdlib.h>
#include "dyArray.h"

int* alloc_array(int size){
	int* temp;
	temp = (int*)calloc(size,sizeof(int));
	if(temp==NULL){
		puts("alloc_array failed");
		return NULL;
	}
	return temp;
} 

void realloc_array(int* ptr,int size){
	int *temp = ptr;
	ptr = realloc(ptr,size*sizeof(int));
	if(!ptr){
		puts("Realloc_array falied");
		ptr = temp;
	}
}

