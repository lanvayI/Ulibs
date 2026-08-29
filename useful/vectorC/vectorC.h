#ifndef VECTORC_H
#define VECTORC_H
typedef struct my_vector{
	void *data;
	int size;
	int nItems;
	size_t element_size;
}vector;

vector* Vector_Init(size_t esize);

int EmplaceBack(vector* list,void *data);

void PopBack(vector* list);

void print_info(vector* lista);

unsigned char* IAt(vector* lista,int index, size_t esize);//Item At Index

int remove_at(vector* list, int index);

//Garbabe functions

void add_to_collector(vector* v);
void final_clean();

#endif 
