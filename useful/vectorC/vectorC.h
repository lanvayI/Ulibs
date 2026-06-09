#ifndef VECTORC_H
#define VECTORC_H
//ver sobre macros e #define vector(T) T*
struct my_vector{
	void *data;
	int size;
	int nItems;
	size_t element_size;
};

typedef struct my_vector vector;

vector* Vector_Init(size_t esize);

void EmplaceBack(vector* list,void *data);

void PopBack(vector* list);

void print_info(vector* lista);

unsigned char* IAt(vector* lista,int index, size_t esize);//Item At Index

#endif
