#pragma once;

typedef struct _Node Node;
typedef struct _Table HashMap;

typedef int (*HashFunction)(void *);

HashMap * HashMap_new();

void HashMap_free(HashMap *);

int HashMap_is_empty(HashMap *);

int HashMap_number_associations(HashMap *);

void HashMap_delete_all_associations(HashMap *);

int HashMap_key_is_present(HashMap *, void *);

void HashMap_key_insert(HashMap *, void *, void *);

void * HashMap_get(HashMap *, void *);

void HashMap_delete(HashMap *, void *);

void ** HashMap_all_key(HashMap *);












