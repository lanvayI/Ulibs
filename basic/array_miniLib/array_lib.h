#ifndef ARRAY_LIB_H
#define ARRAY_LIB_H
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
//começar com array ints, dps para outros tipos

void print_array(int *arr, int size, int withSpace); // array, size, bool spaces between numbers?
int array_find(int *arr,int size, int objective);
void array_reverse(int *arr,int size);
void array_copy(int *arr, int *arr2, int size);
void array_bubble_sort(int *arr, int size);
/*

array_sort
*/
#endif	