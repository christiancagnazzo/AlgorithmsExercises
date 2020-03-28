#include "sorting_lib.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

static int* new_int(int n) {
  int* result = (int*) malloc(sizeof(int));
  *result = n;

  return result;
}

static char* new_char(char n) {
  char* result = (char*) malloc(sizeof(char));
  *result = n;

  return result;
}

int compare_ints(int * a, int * b){ 
  return * (int *) a - * (int *) b;
}

int compare_string(char * a, char * b){ 
  return strcmp(a,b);
}

void test_array_int_equals(){
  int ** array;
  array = malloc(sizeof(int *)*3);
  array[0] = new_int(2);
  array[1] = new_int(2);
  array[2] = new_int(2);
  
  Sorting_Lib_quick_sort((void*)array,(SortingLibCmp) compare_ints, 0,2);

  TEST_ASSERT_EQUAL(2, * (int *)array[0]);
  TEST_ASSERT_EQUAL(2, * (int *)array[1]);
  TEST_ASSERT_EQUAL(2, * (int *)array[2]);
  
  free(array);
}

void test_array_int_disordered(){
  int ** array;
  array = malloc(sizeof(int *)*3);
  array[0] = new_int(3);
  array[1] = new_int(7);
  array[2] = new_int(2);

  TEST_ASSERT_EQUAL(3, * (int *)array[0]);
  TEST_ASSERT_EQUAL(7, * (int *)array[1]);
  TEST_ASSERT_EQUAL(2, * (int *)array[2]);

  Sorting_Lib_quick_sort((void*)array,(SortingLibCmp) compare_ints, 0,2);

  TEST_ASSERT_EQUAL(2, * (int *)array[0]);
  TEST_ASSERT_EQUAL(3, * (int *)array[1]);
  TEST_ASSERT_EQUAL(7, * (int *)array[2]);

  free(array);
}

void test_grow_int_array(){
  int ** array;
  array = malloc(sizeof(int *)*3);
  array[0] = new_int(3);
  array[1] = new_int(4);
  array[2] = new_int(5);

  Sorting_Lib_quick_sort((void*)array,(SortingLibCmp) compare_ints, 0,2);

  TEST_ASSERT_EQUAL(3, * (int *) array[0]);
  TEST_ASSERT_EQUAL(4, * (int *) array[1]);
  TEST_ASSERT_EQUAL(5, * (int *) array[2]);

  free(array);
}

void test_desc_int_array(){
  int ** array;
  array = malloc(sizeof(int *)*3);
  array[0] = new_int(5);
  array[1] = new_int(4);
  array[2] = new_int(3);

  Sorting_Lib_quick_sort((void*)array,(SortingLibCmp) compare_ints, 0,2);

  TEST_ASSERT_EQUAL(3, * (int *) array[0]);
  TEST_ASSERT_EQUAL(4, * (int *) array[1]);
  TEST_ASSERT_EQUAL(5, * (int *) array[2]);

  free(array);
}

void test_one_int_array(){
  int ** array;
  array = malloc(sizeof(int *)*1);
  array[0] = new_int(5);
  
  Sorting_Lib_quick_sort((void*)array,(SortingLibCmp) compare_ints, 0,0);

  TEST_ASSERT_EQUAL(5, * (int *) array[0]);
  
  free(array);
}


void test_array_char(){
  char ** a = malloc(sizeof(char)*3);
  a[0] = new_char('C');
  a[1] = new_char('O');
  a[2] = new_char('A');
  
  Sorting_Lib_quick_sort((void*)a,(SortingLibCmp) compare_string, 0,2);

  TEST_ASSERT_EQUAL('A',* (char *)a[0]);
  TEST_ASSERT_EQUAL('C',* (char *)a[1]);
  TEST_ASSERT_EQUAL('O',* (char *)a[2]);

  free(a);
}

void test_empty_array(){
  char ** a = NULL;

  Sorting_Lib_quick_sort((void *)a, (SortingLibCmp) compare_string,0,0);

  TEST_ASSERT_EQUAL(NULL, a);
}

int main(){
  UNITY_BEGIN();
  
  RUN_TEST(test_array_int_disordered);
  RUN_TEST(test_grow_int_array);
  RUN_TEST(test_desc_int_array);
  RUN_TEST(test_one_int_array);
  RUN_TEST(test_array_char);
  RUN_TEST(test_array_int_equals);
  RUN_TEST(test_empty_array);

  UNITY_END();
}
