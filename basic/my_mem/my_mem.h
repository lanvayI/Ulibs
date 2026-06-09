#ifndef MY_MEM_H
#define MY_MEM_H

void* my_memset(void* src, int value, size_t length);
void* my_memcpy(void* src, void* destiny, size_t length);
void* my_memmove(const void* src,void* dest, size_t length);

#endif