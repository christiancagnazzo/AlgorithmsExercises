#include "order_lib.h"
#include <string.h>

void InsertionSort(void * array, OrderLibCmp compare, int NumElements, size_t SizeElements){
    int i,j;
    void *temp;
    
    
    for (i = 1; i < NumElements; i++){ 
        j = i;
        while (j>0 && compare(array+(SizeElements*j),array+(SizeElements*(j-1))) < 0){
            Swap(array, j, j-1, SizeElements);
            j--;
        }
    }
}

void Swap(void *array, int i, int j, size_t size){
    char temp[size];
    char *a = (char*)array;

    memcpy(temp, (a + size * i), size);
    memcpy((a + size * i), (a + size * j), size);
    memcpy((a + size * j), temp, size);
}


