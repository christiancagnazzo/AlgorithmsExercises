#pragma once

typedef struct _Node Node;
typedef struct _HashMap HashMap;

typedef int (*HashFunction)(void *);
typedef int (*KeyCompare)(void *, void *);

/* Return a hashmap pointer with an initial input capacity. 
  Requires the hash function and a function to compare the values */
HashMap * HashMap_new(HashFunction, KeyCompare, int);

/* Removes hashmap and node pointers from memory */
void HashMap_free(HashMap *);

/* Return true (1) if the hashmap contains no keys, else return false (0) */
int HashMap_is_empty(HashMap *);

/* Inserts a new key-value pair into the hashmap passed as input. 
  It also requires as input a pointer to the key and a pointer to the value
  If the key exists, it replaces the corresponding value with the one passed in input */
void HashMap_insert(HashMap *, void *, void *);

/* Removes the key-value pair to which the key value points
 from the hashmap passed in input */
void HashMap_delete(HashMap *, void *);

/* Rreturn a pointer to the value corresponding to the
 key passed in input. if it does not exist, return null*/
void * HashMap_get_value(HashMap *, void *);

/* Return the number of key-value pairs present in the hasmaph*/
int HashMap_number_associations(HashMap *);

/* Removes all key-value pairs present within the hasmaph */
void HashMap_delete_all_associations(HashMap *);

/* Return true (1) if the key passed as input exists inside 
 the hashmap otherwise it return false (0) */
int HashMap_key_is_present(HashMap *, void *);

/* Return a pointer to an array that contains all the keys present in the hashmap */
void ** HashMap_all_keys(HashMap *);






