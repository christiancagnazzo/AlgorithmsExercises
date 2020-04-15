#pragma once

typedef struct _Node Node;
typedef struct _HashMap HashMap;

typedef int (*HashFunction)(void *);
typedef int (*KeyCompare)(void *, void *);

HashMap * HashMap_new(HashFunction, KeyCompare, int);

void HashMap_free(HashMap *);

int HashMap_is_empty(HashMap *);

void HashMap_insert(HashMap *, void *, void *);

void HashMap_delete(HashMap *, void *);

void * HashMap_get_value(HashMap *, void *);

int HashMap_number_associations(HashMap *);

void HashMap_delete_all_associations(HashMap *);

int HashMap_key_is_present(HashMap *, void *);

void ** HashMap_all_keys(HashMap *);











