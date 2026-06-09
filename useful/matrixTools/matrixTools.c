#include "matrixTools.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
Matrix** m_array = NULL; // -> FC = Final Clean
int m_arr_size = 0;
int m_arr_items = 0;

void add_matrix_to_FC(Matrix* m){
	if(m_array == NULL){
		m_array = (Matrix**)malloc(sizeof(Matrix*));
		if(m_array == NULL){puts("add_matrix_to_FC : malloc failed"); return;}
		m_arr_size++;
		#ifdef DEBUG
		puts("add_matrix_to_fc : m_array allocated");
		#endif
	}
	if(m_arr_items + 1 > m_arr_size){		
		Matrix** tmp = realloc(m_array,sizeof(Matrix*)* (m_arr_size+1));
		if(tmp == NULL){puts("add_matrix_to_FC : realloc failed\n"); return;}
		m_array = tmp;
		m_arr_size+=1;
	}	
	m_array[m_arr_items] = m;
	m_arr_items++;
	#ifdef DEBUG
	printf("add_matrix_to_fc : sucess, added 1, total: %d\n",m_arr_items);
	#endif
}

void final_clean(){
	#ifdef DEBUG
	printf("final_clean : start, items: %d, size %d\n",m_arr_items,m_arr_size);
	#endif
	for(int i=0; i < m_arr_items; i++){
		if(m_array[i] == NULL){continue;}
		m_free(&m_array[i]);
	}
	free(m_array);
	m_array = NULL;
	#ifdef DEBUG
	printf("final_clean : sucess\n");
	#endif
}

Matrix* m_init(int x,int y,size_t element_size,TYPE tipo){
	Matrix *tmp = (Matrix*)malloc(sizeof(Matrix));
	if(tmp == NULL){puts("m_init aloc failed\n"); return NULL;}

	void* tmpArr = malloc(element_size*x*y);
	if(tmpArr==NULL){
		puts("m_init tmpArr aloc failed\n");
		free(tmp);
		return NULL;}


	tmp->arr = tmpArr;
	tmp->x = x; tmp->y = y;
	tmp->esize = element_size;
	tmp->type = tipo;
	add_matrix_to_FC(tmp);
	#ifdef DEBUG
	printf("m_init : sucess > x: %d, y: %d esize: %llu\n",x,y,element_size);
	#endif
	return tmp;
}

Matrix* m_copy(Matrix* src){
	Matrix* m = m_init(src->x, src->y, src->esize, src->type);
	if(m == NULL){puts("m_copy : failed to init matrix\n"); return NULL;}
	
	memcpy(m->arr,src->arr, src->esize * src->x * src->y);
	#ifdef DEBUG
	printf("m_copy : sucess\n");
	#endif
	return m; 	
}

void m_set_all(Matrix* m, void* value){
	for(int i=0; i< m->x * m->y; i++){
	memcpy((unsigned char*)m->arr + m->esize*i, value, m->esize);
	}
	#ifdef DEBUG
	switch(m->type){
	case INT:
	printf("m_set_all : sucess > value: %d\n",*((int*)value)); break;
	case FLOAT:
	printf("m_set_all : sucess > value: %.2f\n",*((float*)value)); break;
	case DOUBLE:
	printf("m_set_all : sucess > value: %.2f\n",*((double*)value)); break;
}
	#endif
}

void m_set(Matrix* m, void* value, int x, int y){
	if(x >= m->x || y >= m->y){puts("m_set : cordinate go out of bounds\n"); return;}
	memcpy((unsigned char*)m->arr + (m->esize*x + m->esize*y*m->x), value, m->esize);
	#ifdef DEBUG
	switch(m->type){
	case INT:
	printf("m_set : sucess > x: %d, y: %d value: %d\n",x,y,*((int*)value)); break;
	case FLOAT:
	printf("m_set : sucess > x: %d, y: %d value: %.2f\n",x,y,*((float*)value)); break;
	case DOUBLE:
	printf("m_set : sucess > x: %d, y: %d value: %.2f\n",x,y,*((double*)value)); break;
}
	#endif

}

void m_set_alot(Matrix* m,...){
	va_list args;
	va_start(args,m);

	for(int i=0; i< m->x * m->y; i++){
		switch(m->type){
		case INT: *((int*)m->arr+ i) = va_arg(args, int); break;
		case FLOAT: puts("m_set_alot : cant use varidic args smth like that i am lazy to fix this rn, just use double"); return; 
		case DOUBLE: *((double*)m->arr + i) = va_arg(args, double); break;
		}
	}
	va_end(args);
	#ifdef DEBUG
	puts("m_set_alot : finished");
	#endif
}

unsigned char* m_at(Matrix*m, int x,int y){
	if(x >= m->x || y >= m->y){puts("m_at : out of bounds acess\n"); return NULL;}
	#ifdef DEBUG
	printf("m_at : x: %d, y: %d\n",x,y);
	unsigned char* value = (unsigned char*)m->arr + m->esize*x + m->esize*m->x * y;
	switch(m->type){
	case INT:
	printf("m_at : sucess > value: %d\n",*((int*)value)); break;
	case FLOAT:
	printf("m_at : sucess > value: %.2f\n",*((float*)value)); break;
	case DOUBLE:
	printf("m_at : sucess > value: %.2f\n",*((double*)value)); break;
	}
	#endif
	return (unsigned char*)m->arr + m->esize*x + m->esize*m->x * y;
}

void m_print(Matrix* m){
	int k=0;
	for(int i=0; i<m->y; i++){
		for(int j=0; j<m->x; j++){
			switch(m->type){
			case INT:
				printf("%d ",*((int*)m->arr + k)); break;
			case FLOAT:
				printf("%.2f ",*((float*)m->arr + k)); break;
			case DOUBLE:
				printf("%.2f ",*((double*)m->arr + k)); break;
			}
		k++;
		}
	puts("");
	}
}

void m_free(Matrix** m){
	if(m == NULL || *m ==NULL){puts("m_free : cant free null pointer\n");return;}
	
	free((*m)->arr);
	(*m)->arr = NULL;
	free((*m));
	(*m) = NULL;
	#ifdef DEBUG
	puts("m_free ocurred");
	#endif
}

int is_sqr(Matrix *m){
	if(m->x == m->y){return 1;}
	return 0;
}

int is_size_equal(Matrix *m, Matrix *m2){
	if(m->x != m2->x || m->y != m2->y){return 0;}
	return 1;
}

void* get_primary_diagonal(Matrix* m){
	if(m->x != m->y){puts("get_primary_diagonal : matrix is not a square\n");return NULL;}
	void* diag = malloc(m->esize*m->x);
	for(int i=0; i<m->x; i++){
		memcpy((unsigned char*)diag + m->esize*i, m_at(m,i,i), m->esize);
	}	
	return diag;
}

void* get_secondary_diagonal(Matrix* m){
	if(m->x != m->y){puts("get_sencondary_diagonal : matrix is not a square\n");return NULL;}
	void* diag = malloc(m->esize*m->x);
	int x = m->x-1, y = 0;
	for(int i=0; i<m->x;i++){
		memcpy((unsigned char*)diag + m->esize*i, m_at(m,x,y), m->esize);
		x--; y++;
	}
	return diag;
}

Matrix* m_add(Matrix* m1, Matrix* m2){
	if(!is_size_equal(m1,m2)){puts("m_add : cant add matrices with different sizes\n"); return NULL;}
	if(m1->type != m2->type){puts("m_add > cant add matrices with different types\n"); return NULL;}
	Matrix *tmp = m_copy(m1);
	for(int i=0; i<m1->x*m1->x; i++){
		switch(m1->type){
			case INT:
			*((int*)tmp->arr + i) += *((int*)m2->arr + i);
			break;
			
			case FLOAT:
			*((float*)tmp->arr + i) += *((float*)m2->arr + i);
			break;

			case DOUBLE:
			*((double*)tmp->arr + i) += *((double*)m2->arr + i);
			break;
	}		
	}
	#ifdef DEBUG
	puts("m_add : sucess\n");
	#endif
	return tmp;	
}

Matrix* m_multiply(Matrix* m1, Matrix* m2){
	if(m1->y != m2->x){puts("m_multiply : cant multiply when m1 y is not equal to m2 x"); return NULL;}
	if(m1->type != m2->type){puts("m_multiply : cant multiply different types"); return NULL;}

	Matrix* res = m_init(m1->y,m2->x,m1->esize,m1->type);
	if(res == NULL){puts("m_multiply : allocation for result matrix failed"); return NULL;}

		//*((unsigned char*)res->arr + res->esize*i) 
	void* op_res = malloc(m1->esize);
	void* v1 = malloc(m1->esize);
	void* v2 = malloc(m2->esize);
	for(int i=0; i < m1->y; i++){
	for(int j=0; j < m2->x; j++){
		memset(op_res, 0, m1->esize);
	for(int k=0; k < m1->x; k++){
		switch(m1->type){
		case INT:
		*((int*)v1) = *((int*)m_at(m1,k,i));
		*((int*)v2) = *((int*)m_at(m2,j,k));
		*((int*)op_res) += *((int*)v1) * *((int*)v2);
		break;
		case FLOAT:
		*((float*)v1) = *((float*)m_at(m1,k,i));
		*((float*)v2) = *((float*)m_at(m2,j,k));
		*((float*)op_res) += *((float*)v1) * *((float*)v2);
		break;
		case DOUBLE:
		*((double*)v1) = *((double*)m_at(m1,k,i));
		*((double*)v2) = *((double*)m_at(m2,j,k));
		*((double*)op_res) += *((double*)v1) * *((double*)v2);
		break;
	}
	}
	
	m_set(res,op_res,j,i);
	}
	}
	
	return res;
}
