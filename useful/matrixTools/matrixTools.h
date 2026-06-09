#ifndef MATRIXTOOLS_H
#define MATRIXTOOLS_H
typedef enum  {INT,DOUBLE,FLOAT} TYPE;

typedef struct{
	void* arr;
	int x,y;
	size_t esize; //element size
	TYPE type;
}Matrix;

//basic functions to be able to deal with matrices
void add_matrix_to_FC(Matrix* m);
void final_clean(); 

Matrix* m_init(int x,int y,size_t element_size,TYPE tipo);
Matrix* m_copy(Matrix* src);
void m_set_all(Matrix* m, void* value);
void m_set(Matrix* m, void* value, int x, int y);
void m_set_alot(Matrix* m,...);
unsigned char* m_at(Matrix*m, int x,int y);
void m_print(Matrix* m);
void m_free(Matrix** m);

// operations with matrices
int is_sqr(Matrix *m);
int is_size_equal(Matrix *m, Matrix *m2);
void* get_primary_diagonal(Matrix* m);
void* get_secondary_diagonal(Matrix* m);
Matrix* m_add(Matrix* m1, Matrix* m2); 
Matrix* m_multiply(Matrix* m1, Matrix* m2);
#endif
