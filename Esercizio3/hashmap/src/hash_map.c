#include "hash_map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define LOAD_FACTORY_UP 75
#define LOAD_FACTORY_DOWN 10


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


int HashMap_get_position(HashMap * hash_map, int hash_code){
  int position = hash_code % hash_map->table_capacity; 
  return position;
}

Node * HashMap_new_node(void * key, void * value){
  Node * result = (Node*) malloc(sizeof(Node));
  result->key = key;
  result->value = value;
  result->next = NULL;
  result->prev = NULL;
  return result;
}


HashMap * HashMap_new(HashFunction hash_fun, KeyCompare cmp, int capacity){ 
  HashMap * result = (HashMap*) malloc(sizeof(HashMap));
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


void HashMap_resize(HashMap * hash_map, int memsize){
  HashMap * new_hash_map = HashMap_new(hash_map->hash_fun, hash_map->cmp, memsize);
  for (int i = 0; i < hash_map->table_capacity; i++){
    Node * current = hash_map->table[i];
    while (current != NULL){
      HashMap_insert(new_hash_map,current->key,current->value);
      current = current->next;
    }
  }

  hash_map->table_capacity = new_hash_map->table_capacity;
  hash_map->num_elements = new_hash_map->num_elements;

  Node** tmp_table = hash_map->table;
  hash_map->table = new_hash_map->table;
  new_hash_map->table = tmp_table;
  free(new_hash_map);
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
  int pos = HashMap_get_position(hash_map,hash_map->hash_fun(key));

  Node * current = hash_map->table[pos];
  while (current != NULL){
    if (hash_map->cmp(current->key,key) == 0)
      return TRUE;
    current = current->next;
  }
  
  return FALSE;
}


void HashMap_insert(HashMap * hash_map, void * key, void * value){
  int load = hash_map->num_elements * 100 / hash_map->table_capacity;
  
  if (load > LOAD_FACTORY_UP){
    HashMap_resize(hash_map,hash_map->table_capacity*2);
  }

  if (!HashMap_key_is_present(hash_map,key)){
  
    Node * new = HashMap_new_node(key,value);
    
    int pos = HashMap_get_position(hash_map,hash_map->hash_fun(key));
    
    if (hash_map->table[pos] != NULL){
      new->next = hash_map->table[pos];
      new->next->prev = new;  
    }
   
    hash_map->table[pos] = new;
    hash_map->num_elements++;
  }
  else {
    int pos = HashMap_get_position(hash_map,hash_map->hash_fun(key));

    Node * current = hash_map->table[pos];
    while (hash_map->cmp(current->key,key) != 0){
      current = current->next;
    }

    current->value = value;
  }
}


void * HashMap_get_value(HashMap * hash_map, void * key){
  int pos = HashMap_get_position(hash_map,hash_map->hash_fun(key));
  
  Node * current = hash_map->table[pos];
  while (current != NULL){
    if (hash_map->cmp(current->key,key) == 0)
      return current->value;
    current = current->next;  
  }  

  return NULL;   
}


void HashMap_delete(HashMap * hash_map, void * key){
  int load = hash_map->num_elements * 100 / hash_map->table_capacity;
  
  if (load < LOAD_FACTORY_DOWN){
    HashMap_resize(hash_map,hash_map->table_capacity/2);
  }
  
  int pos = HashMap_get_position(hash_map,hash_map->hash_fun(key));

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


void ** HashMap_all_values(HashMap * hash_map){
  void ** values = (void **) malloc(sizeof(void *)*hash_map->num_elements);

  int j = 0;
  for (int i = 0; i < hash_map->table_capacity; i++){
    Node * current = hash_map->table[i];
    while (current != NULL){
      values[j++] = current->value; 
      current = current->next;
    }
  }
  
  return values;
}

