#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H 

#include <__stddef_size_t.h>

typedef struct _vector {
  void *values;
  size_t size;
  size_t cnt;
} Vector;

void vec_init(Vector *v, void *values, size_t size);
int vec_memory_supply(Vector *v, size_t current_size, size_t size_value);
void vec_free(Vector *v);

// int *pt = (int *) v.values + 1; // since the casting is done in first place add 7 will add 7 * 4 bytes to the address of values 
// int *pt2 = (int *) (v.values + 1 * sizeof(int)); // in this case sizeof is required
#define vec_push(v_ptr, value, type) {                            \
  size_t current_size = (v_ptr)->size & ~(size_t)1;               \
  if((v_ptr)->cnt == current_size)                                \
    if(!vec_memory_supply((v_ptr), current_size, sizeof(type)))   \
      exit(1);                                                    \
  * ((type *) (v_ptr)->values + (v_ptr)->cnt) = value;            \
  (v_ptr)->cnt++; } 

#define vec_get_value(v_ptr, i, type) (* ((type *) (v_ptr)->values + i))

#endif // !DYNAMIC_ARRAY.H
