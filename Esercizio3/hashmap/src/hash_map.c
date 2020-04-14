#include "hash_map.h";

#define INITIAL_CAPACITY 100

struct _Node {
  void * key;
  void * value;
  Node * next;
};

struct _HashMap {
  int size;
  int capacity;
  Node ** table;
};





