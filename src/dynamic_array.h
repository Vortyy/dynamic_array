#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H 

#include <__stddef_size_t.h>

typedef struct _vector {
  size_t size;
  size_t cnt;
  int *values;
} Vector;

void vec_init(Vector *v, int *values, size_t size);
int vec_push(Vector *v, int t);
void vec_free(Vector *v);

#endif // !DYNAMIC_ARRAY.H
