#include <stdio.h>
#include "array_lib.h"

void print_array(int* arr, int size,int withSpace){
	for(int i=0; i< size; i++){
		withSpace ? printf("%d ",arr[i]) : printf("%d",arr[i]);
	}
}

int array_find(int *arr,int size, int objective){
	for(int i=0; i < size; i++){
		if(objective == arr[i]){return 1;}
	}
	return 0;
}

void array_reverse(int* arr,int size){
	for(int i=0;i<size/2;i++){
		int temp = arr[i];
		arr[i] = arr[size-i-1];
		arr[size-i-1] = temp;
	}
}

void array_copy(int *arr, int *arr2, int size){
	for(int i=0;i<size;i++){
		arr2[i] = arr[i];
	}
}
// bubble sort stuff

void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void array_bubble_sort(int *arr, int size){
	int madeSmth = 0;
	while(1){
		madeSmth = 0;
		for(int i=0;i<size-1;i++){
			if(arr[i] > arr[i+1]){
				swap(&arr[i],&arr[i+1]);
				madeSmth = 1;
			}
		}
		if(madeSmth==0){return;}
	}
}

