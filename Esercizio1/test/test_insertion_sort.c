#include <stdlib.h>
#include "unity.h"
#include "order_lib.h"

int compareInts(int * a, int * b){ 
    return * (int *) a - * (int *) b;
}

int compareString(char * a, char * b){ 
    return strcmp(a,b);
}


/* array vuoto */

void testArrayIntDisordered(){
    int * array;
    array = malloc(sizeof(int)*3);
    array[0] = 3;
    array[1] = 7;
    array[2] = 2;

    TEST_ASSERT_EQUAL(3, array[0]);
    TEST_ASSERT_EQUAL(7, array[1]);
    TEST_ASSERT_EQUAL(2, array[2]);

    InsertionSort(array,(OrderLibCmp) compareInts, 3, sizeof(int));

    TEST_ASSERT_EQUAL(2, array[0]);
    TEST_ASSERT_EQUAL(3, array[1]);
    TEST_ASSERT_EQUAL(7, array[2]);

    free(array);
}

void testGrowArrayInt(){
    int * array;
    array = malloc(sizeof(int)*3);
    array[0] = 3;
    array[1] = 4;
    array[2] = 5;

    InsertionSort(array,(OrderLibCmp) compareInts, 3, sizeof(int));

    TEST_ASSERT_EQUAL(3, array[0]);
    TEST_ASSERT_EQUAL(4, array[1]);
    TEST_ASSERT_EQUAL(5, array[2]);

    free(array);
}

void testDescArrayInt(){
    int * array;
    array = malloc(sizeof(int)*3);
    array[0] = 5;
    array[1] = 4;
    array[2] = 3;

    InsertionSort(array,(OrderLibCmp) compareInts, 3, sizeof(int));

    TEST_ASSERT_EQUAL(3, array[0]);
    TEST_ASSERT_EQUAL(4, array[1]);
    TEST_ASSERT_EQUAL(5, array[2]);

    free(array);
}

void testOneElArrayInt(){
    int * array;
    array = malloc(sizeof(int)*3);
    array[0] = 5;
    
    InsertionSort(array,(OrderLibCmp) compareInts, 1, sizeof(int));

    TEST_ASSERT_EQUAL(5, array[0]);
    
    free(array);
}


void testArrayChar(){
    char * a = malloc(sizeof(char)*3);
    a[0] = 'C';
    a[1] = 'O';
    a[2] = 'A';
    
    InsertionSort(a,(OrderLibCmp) compareString, 3, sizeof(char));

    TEST_ASSERT_EQUAL('A',a[0]);
    TEST_ASSERT_EQUAL('C',a[1]);
    TEST_ASSERT_EQUAL('O',a[2]);

    free(a);
}



int main(){
    UNITY_BEGIN();

    RUN_TEST(testArrayIntDisordered);
    RUN_TEST(testGrowArrayInt);
    RUN_TEST(testDescArrayInt);
    RUN_TEST(testOneElArrayInt);
    RUN_TEST(testArrayChar);

    UNITY_END();

}