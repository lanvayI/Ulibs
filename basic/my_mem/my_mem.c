#include "my_mem.h"

void* my_memset(void* src, int value, size_t length){
	unsigned char* tempArr = (void *)src;
	for(size_t i=0;i<length;i++){
		tempArr[i] = value;
	}
	return src;
}

void* my_memcpy(void* src, void* destiny, size_t length){
	unsigned char* tempSrc = (void *)src;
	unsigned char* tempDest = (void *)destiny;
	for(size_t i=0; i<length; i++){
		tempDest[i] = tempSrc[i];
	}
	return destiny;
}

void* my_memmove(const void* src,void* dest, size_t length){
	const unsigned char* tempSrc = (void *)src;
	unsigned char* tempDest = (void *)dest;
	
	if(tempSrc == 0 || tempDest == 0){return dest;}
	if(tempDest < tempSrc){
		for(size_t i=0; i<length;i++){
			tempDest[i] = tempSrc[i];
		}
	}else{
		for(size_t i=length; i > 0; i--){
			tempDest[i-1] = tempSrc[i-1];
		}
	}
	return dest;
}
