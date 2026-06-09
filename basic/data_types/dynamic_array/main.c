#include <stdio.h>
#include "dyArray.h"
#include "dyArray.c"

int main(){
	int* ptr = alloc_array(1);
	for(int i=0;i<25;i++){
		ptr[i]=i;
	}
	for(int i=0; i< 50; i++){
		printf("%i ",ptr[i]);
	}

	free(ptr);
	ptr=NULL;
	return 0;
}