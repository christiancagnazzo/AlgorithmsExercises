#include <stdio.h>
#include <string.h>
#include "sorting_lib.h"
#include <stdlib.h>
#include <time.h>

#define ERROR_EXIT_CODE 1
#define SIZE_ARRAY 20000000 
#define SIZE_PRINT_TEST 10

typedef struct {
  int id;
  char * field_one;
  int field_two;
  float field_three;
 } Record;

 typedef struct {
  char const * file_name;   
  SortingLibCmp comparison_fun;
  int algorithm;
 } Options;

void print_usage() {
  printf("Usage: app < -1 | -2 > < -A -B -C > <filename>\n");
  printf("  -1: sort through the insertion sort algorithm\n");
  printf("  -2: sort through the quick sort algorithm\n");
  printf("  -3: sort through the quick sort three way algorithm\n");
  printf("  -A: sort according to the first field ascending order\n");
  printf("  -B: sort according to the second field ascending order\n");
  printf("  -C: sort according to the third field ascending order\n");
}

int compare_first_field(Record * rec1, Record * rec2){
  return strcmp(rec1->field_one,rec2->field_one);
}

int compare_second_field(Record * rec1, Record * rec2){
  return rec1->field_two - rec2->field_two;
}

int compare_third_field(Record * rec1, Record * rec2){
  if (rec1->field_three > rec2->field_three)
    return 1;
  else if (rec1->field_three < rec2->field_three)
    return -1;
  else return 0;
}

Options parse_options(int argc, char const *argv[]){
  if (argc != 4){
    printf("Parameters error\n");
    print_usage();
    exit(ERROR_EXIT_CODE);
  }

  Options options;
  
  if (!strcmp(argv[2],"-A"))
    options.comparison_fun = (SortingLibCmp) compare_first_field;
  else if (!strcmp(argv[2],"-B"))
    options.comparison_fun = (SortingLibCmp) compare_second_field;
    else if (!strcmp(argv[2],"-C"))
      options.comparison_fun = (SortingLibCmp) compare_third_field;
    else {
      printf("Parameters error\n");
      print_usage();
      exit(ERROR_EXIT_CODE);
    }
  
  if (!strcmp(argv[1], "-1"))
    options.algorithm = 1;
  else if (!strcmp(argv[1], "-2"))
    options.algorithm = 2;
  else if (!strcmp(argv[1], "-3"))
    options.algorithm = 3;
    else {
      printf("Parameters error\n");
      print_usage();
      exit(ERROR_EXIT_CODE);
  }
  
  options.file_name = argv[3];

  return options;
}

void load_data(Record ** array, const char * file_name){
  FILE * file = fopen(file_name,"r");

  #define MAX_BUF_LEN 1024
  int id;
  char field_one[MAX_BUF_LEN];
  int field_two;
  float field_three;
  int i = 0;

  while (!feof(file) && i < SIZE_ARRAY){
    Record * record = malloc(sizeof(Record));
  
    int n = fscanf(file, "%d,%1024[^,],%d,%f\n", &id, field_one, &field_two, &field_three);

    if (n != 4) {
      if (feof(file)) {
          continue;
      }
      printf("Error while reading file");
      exit(ERROR_EXIT_CODE);
    }

    record->id = id;
    record->field_one = strndup(field_one, MAX_BUF_LEN);
    record->field_two = field_two;
    record->field_three = field_three;

    array[i] = record;
    i++;
  }

  fclose(file);
}

void free_data(Record ** array){
  for (int i = 0; i < SIZE_ARRAY; i++)
    free(array[i]);
  free(array);
}

void test_print(Record ** array, int elem){
  int s = 0;
  for (int i = 0; i < elem; i++){
    Record * rec = array[i];
    printf("ID: %d\t FIELD_ONE: %s\t\t FIELD_TWO: %d\t FIELD_THREE: %f\n",rec->id,rec->field_one,rec->field_two,rec->field_three);
  }
}

int main(int argc, char const *argv[]){
  Options options = parse_options(argc, argv);
  Record ** array = malloc(sizeof(Record *)*SIZE_ARRAY); 
  load_data(array, options.file_name);
  clock_t start = clock();
  if (options.algorithm == 1)
    SortingLib_insertion_sort((void **) array,options.comparison_fun,SIZE_ARRAY);
  else if (options.algorithm == 2) 
    SortingLib_quick_sort((void**) array,options.comparison_fun,0,SIZE_ARRAY-1);
  else if (options.algorithm == 3)
    SortingLib_three_way_quicksort((void **) array,options.comparison_fun,0,SIZE_ARRAY-1);
  clock_t end = clock();
  printf("Sorting time: %f\n",(double)(end-start)/CLOCKS_PER_SEC);
  test_print(array,SIZE_PRINT_TEST);
  free_data(array);
}




