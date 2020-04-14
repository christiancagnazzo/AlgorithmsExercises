#include "hash_map.h"
#include <stdlib.h>
#include <stdio.h>

struct _Node {
  void * key;
  void * value;
  Node * next;
  Node * prev;
};

struct _HashMap {
  int num_elemets;
  int table_capacity;
  Node ** table;
  HashFunction hash_fun;
};

HashMap * HashMap_new(HashFunction hash_fun, int capacity){  /* capacità utente?? */
  HashMap * result = (HashMap*) malloc(sizeof(HashMap));
  result->num_elemets = 0;
  result->table_capacity = capacity;
  void ** table = (void**) malloc(sizeof(void*)*result->table_capacity);
  for (int i = 0; i < result->table_capacity; i++) 
    table[i] = NULL;
  result->table = table;
  result->hash_fun = hash_fun;
  return result;
}

void HashMap_free(HashMap * hash_map){ /* ?? */
  free(hash_map->table);
  free(hash_map);
}

int HashMap_is_empty(HashMap * hash_map){
  return !(hash_map->num_elemets);
}

void HashMap_insert(HashMap * hash_map, void * key, void * value){ /* controllo se c'è gia?? */
  int pos = hash_map->hash_fun(key) % hash_map->table_capacity;
  
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

  hash_map->num_elemets++;
}

void HashMap_delete(HashMap * hash_map, void * key){ /* funzione di comparizione */
  int pos = hash_map->hash_fun(key) % hash_map->table_capacity;

  if (hash_map->table[pos] != NULL){
    Node * current = hash_map->table[pos];
    while (current != NULL && current->key != key)
      current = current->next;
    if (current != NULL){
      if (current->prev != NULL)
        current->prev->next = current->next;
      else
        hash_map->table[pos] = current->next;  
      if (current->next != NULL)  
        current->next->prev = current->prev;
      free(current);
      hash_map->num_elemets--;
    }
  }
}









