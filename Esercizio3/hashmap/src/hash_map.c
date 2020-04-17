#include "hash_map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

struct _Node {
  void * key;
  void * value;
  Node * next;
  Node * prev;
};

struct _HashMap {
  int num_elements;
  int table_capacity;
  Node ** table;
  HashFunction hash_fun;
  KeyCompare cmp;
};


HashMap * HashMap_new(HashFunction hash_fun, KeyCompare cmp, int capacity){ 
  HashMap * result = (HashMap*) (void **) malloc(sizeof(HashMap));
  result->num_elements = 0;
  result->table_capacity = capacity;
  Node ** table = (Node **) malloc(sizeof(Node*)*result->table_capacity);
  for (int i = 0; i < result->table_capacity; i++) 
    table[i] = NULL;
  result->table = table;
  result->hash_fun = hash_fun;
  result->cmp = cmp;
  return result;
}


static int get_position(HashMap * hash_map, int hash_code){
  int position = hash_code % hash_map->table_capacity; 
  return position;
  }


HashMap * HashMap_resize(HashMap * hash_map, int memsize){
  HashMap * new_hash_map = HashMap_new(hash_map->hash_fun, hash_map->cmp, memsize);
  for (int i = 0; i < hash_map->table_capacity; i++){
    Node * current = hash_map->table[i];
    while (current != NULL){
      HashMap_insert(new_hash_map,current->key,current->value);
      current = current->next;
    }
  }
  return new_hash_map;
}


static int threshold(HashMap * hash_map){
  return (hash_map->table_capacity*3)/4;
}


void HashMap_free(HashMap * hash_map){
  HashMap_delete_all_associations(hash_map);
  free(hash_map->table);
  free(hash_map);
}


int HashMap_is_empty(HashMap * hash_map){
  return !(hash_map->num_elements);
}


int HashMap_number_associations(HashMap * hash_map){
  return hash_map->num_elements;
}


void HashMap_delete_all_associations(HashMap * hash_map){
  for (int i = 0; i < hash_map->table_capacity; i++){
    Node * current = hash_map->table[i];
    while (current != NULL){
      Node * delete = current;
      current = current->next;
      free(delete);
      hash_map->num_elements--;
    }
  hash_map->table[i] = NULL;
  }
}


int HashMap_key_is_present(HashMap * hash_map, void * key){
  int pos = get_position(hash_map,hash_map->hash_fun(key));

  if (hash_map->table[pos] != NULL){
    Node * current = hash_map->table[pos];
    while (current != NULL){
      if (hash_map->cmp(current->key,key) == 0)
        return TRUE;
      current = current->next;
    }
  }

  return FALSE;
}


void HashMap_insert(HashMap * hash_map, void * key, void * value){
  if (!HashMap_key_is_present(hash_map,key)){

    int pos = get_position(hash_map,hash_map->hash_fun(key));
    
    if (hash_map->table[pos] == NULL){
      Node * result = (Node*) malloc(sizeof(Node));
      result->key = key;
      result->value = value;
      result->next = NULL;
      result->prev = NULL;
      hash_map->table[pos] = result;
    } 
    else {
      Node * result = (Node*) malloc(sizeof(Node));
      result->key = key;
      result->value = value;
      result->next = hash_map->table[pos];
      result->prev = NULL;
      result->next->prev = result;
      hash_map->table[pos] = result;  
    }

    hash_map->num_elements++;

    if (hash_map->num_elements == threshold(hash_map)){
      hash_map = HashMap_resize(hash_map, hash_map->table_capacity*2);
    }
  }
}


void * HashMap_get_value(HashMap * hash_map, void * key){
  int pos = get_position(hash_map,hash_map->hash_fun(key));

  if (hash_map->table[pos] != NULL){
    Node * current = hash_map->table[pos];
    while (current != NULL){
      if (hash_map->cmp(current->key,key) == 0)
        return current->value;
      current = current->next;  
    }
  }

  return NULL;
}


void HashMap_delete(HashMap * hash_map, void * key){
  int pos = get_position(hash_map,hash_map->hash_fun(key));

  if (hash_map->table[pos] != NULL){
    Node * current = hash_map->table[pos];
    while (current != NULL && hash_map->cmp(current->key,key) != 0)
      current = current->next;
    if (current != NULL){
      if (current->prev != NULL)
        current->prev->next = current->next;
      else
        hash_map->table[pos] = current->next;  
      if (current->next != NULL)  
        current->next->prev = current->prev;
      free(current);
      hash_map->num_elements--;
    }
  }
}


void ** HashMap_all_keys(HashMap * hash_map){
  void ** keys = (void **) malloc(sizeof(void *)*hash_map->num_elements);

  int j = 0;
  for (int i = 0; i < hash_map->table_capacity; i++){
    Node * current = hash_map->table[i];
    while (current != NULL){
      keys[j++] = current->key; 
      current = current->next;
    }
  }
  
  return keys;
}


