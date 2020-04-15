#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"
#include <time.h>

#define CAPACITY 10000
#define ERROR_EXIT_CODE 1
#define SIZE_ARRAY 6321078

int * int_pointer(int x){
  int * ris = (int *) malloc (sizeof(int));
  *ris = x;
  return ris;
}


int hash_function(int * key){
  return *key % CAPACITY;
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
    HashMap_insert(hash,int_pointer(key),int_pointer(value));

    if(n != 2) {
      if(feof(file)) {
        continue;
      }
      printf("Error while reading file");
      exit(ERROR_EXIT_CODE);
    }
  }

  clock_t end = clock();
  
  printf("Loading time with HashMap: %f sec\n",(double)(end-start)/CLOCKS_PER_SEC);
  fclose(file);
}


void load_data_array(int * array_keys, int * array_value, const char * file_name){
  FILE * file = fopen(file_name, "r");
  int key, value;
  int i = 0;
  
  clock_t start = clock();
  
  while (!feof(file)){
    int n = fscanf(file,"%d,%d\n",&key,&value);
    array_keys[i] = key;
    array_value[i++] = value;
  
    if(n != 2) {
      if(feof(file)) {
        continue;
      }
      printf("Error while reading file");
      exit(ERROR_EXIT_CODE);
    }
  }

  clock_t end = clock();
  
  printf("Loading time with Array: %f sec\n",(double)(end-start)/CLOCKS_PER_SEC);
  fclose(file);
}


int main(int argc, char const *argv[]) {
  if (argc != 2){
    printf("Parameters error\n");
    exit(ERROR_EXIT_CODE);
  }
  
  /* LOAD DATA HASH MAP*/
  HashMap * hash = HashMap_new((HashFunction) hash_function, (KeyCompare) compare_keys, CAPACITY);
  load_data_hash_map(hash, argv[1]);
 
  /* LOAD DATA ARRAY*/
  static int array_keys[SIZE_ARRAY];
  static int array_value[SIZE_ARRAY];
  load_data_array(array_keys,array_value,argv[1]);
}