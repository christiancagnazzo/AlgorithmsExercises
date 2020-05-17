#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"
#include "array_lib.h"
#include <time.h>

#define TRUE 1
#define FALSE 0
#define ERROR_EXIT_CODE 1
#define SIZE_ARRAY 6321078
#define NUM_RANDOM_KEYS 10000000
#define CAPACITY 8

int * int_pointer(int x){
  int * ris = (int *) malloc (sizeof(int));
  *ris = x;
  return ris;
}


int hash_function(int * key){
  return (*key);
}


int compare_keys(int * key_one, int * key_two){
  return *key_one - *key_two;
}


void load_data_hash_map(HashMap * hash, const char * file_name){
  FILE * file = fopen(file_name, "r");
  int key, value;
  
  clock_t start = clock();
  
  while (!feof(file)){
    int n = fscanf(file,"%d,%d\n",&key,&value);

    if(n != 2) {
      if(feof(file)) {
        continue;
      }
      printf("Error while reading file");
      exit(ERROR_EXIT_CODE);
    }

    HashMap_insert(hash,int_pointer(key),int_pointer(value));

  }

  clock_t end = clock();
  
  printf("Loading time with HashMap: %f sec\n",(double)(end-start)/CLOCKS_PER_SEC);
  fclose(file);
}


void load_data_array(Couple * array, const char * file_name){
  FILE * file = fopen(file_name, "r");
  int key, value;
  int i = 0;
  
  clock_t start = clock();
  
  while (!feof(file)){
    int n = fscanf(file,"%d,%d\n",&key,&value);
    
    if(n != 2) {
      if(feof(file)) {
        continue;
      }
      printf("Error while reading file");
      exit(ERROR_EXIT_CODE);
    }

    array[i].key = key;
    array[i].value = value; 
    i++;   
  }

  clock_t end_one = clock();

  ArrayLib_quick_sort_int(array,0,SIZE_ARRAY-1);
  
  clock_t end_two = clock();
  
  printf("Loading time with Array: %f sec + Sorting time %f sec (Total %f)\n",
                                              (double)(end_one-start)/CLOCKS_PER_SEC,
                                              (double)(end_two-end_one)/CLOCKS_PER_SEC,
                                              (double)(end_two-start)/CLOCKS_PER_SEC);
  fclose(file);
}


int * get_values_hash_map(HashMap * hash, int * keys){
  int * values = (int *) malloc(sizeof(int)*NUM_RANDOM_KEYS);
  
  clock_t start = clock();

  int num_key = 0;
  for (int i = 0; i < NUM_RANDOM_KEYS; i++){
    int * val = (int *) HashMap_get_value(hash,&keys[i]);
    if (val != NULL){
      values[i] = *val;
      num_key++;
    }
    else
      values[i] = -1;
  }

  clock_t end = clock();
  
  printf("Get values time with HashMap: %f sec - Key founded %d\n",(double)(end-start)/CLOCKS_PER_SEC,num_key);
  return values;
}

int * get_values_array(Couple * array, int * keys){
  int * values = (int *) malloc(sizeof(int)*NUM_RANDOM_KEYS);

  clock_t start = clock();

  int num_key = 0;
  for (int i = 0; i < NUM_RANDOM_KEYS; i++){
    int x =  ArrayLib_binary_search_value(array,keys[i],0,SIZE_ARRAY-1);
    if (x != -1)
      num_key++;
    values[i] = x;
  }
  
  clock_t end = clock();
  
  printf("Get values time with Array: %f sec - Key founded %d\n",(double)(end-start)/CLOCKS_PER_SEC,num_key);
  return values;
}


int check_values(int * hash_value, int * array_value){
  for (int i = 0; i < NUM_RANDOM_KEYS; i++){
    if (hash_value[i] != array_value[i])
      return FALSE;
  }
  return TRUE;
}



// MAIN

int main(int argc, char const *argv[]) {
  if (argc != 2){
    printf("Parameters error. Use: bin/app <file>\n");
    exit(ERROR_EXIT_CODE);
  }
  
  /* LOAD DATA HASH MAP */
  HashMap * hash = HashMap_new((HashFunction) hash_function, (KeyCompare) compare_keys, CAPACITY);
  load_data_hash_map(hash, argv[1]);

  /* LOAD DATA ARRAY */
  static Couple array[SIZE_ARRAY];
  load_data_array(array,argv[1]);

  /* RANDOM KEYS */
  int * keys = (int*) malloc(sizeof(int)*NUM_RANDOM_KEYS);
  srand(time(NULL));
  for (int i = 0; i < NUM_RANDOM_KEYS; i++){
    keys[i] = rand() % (NUM_RANDOM_KEYS+1);
  }

  /* GET VALUES HASH MAP */
  int * values_hash_map = get_values_hash_map(hash, keys);

  /* GET VALUES ARRAY */
  int * values_array = get_values_array(array, keys);

  /* CHECK VALUES*/
  if (check_values(values_hash_map,values_array)) 
    printf("Check finished. Correct values\n");
  else
    printf("Check finished. Not correct values\n");

  /* FREE MEMORY */
  int ** all_keys = (int **) HashMap_all_keys(hash);
  for (int i = 0; i < HashMap_number_associations(hash); i++)
    free(all_keys[i]);
  for (int i = 0; i < NUM_RANDOM_KEYS; i++)
      free(HashMap_get_value(hash, &keys[i]));
  free(all_keys);
  HashMap_free(hash);
  free(keys);
  free(values_hash_map);
  free(values_array);
}