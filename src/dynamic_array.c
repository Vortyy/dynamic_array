// objectif library static dynamic with a dynamic array implementation (ArrayList java)
// type agnostic arraylist in C

//Malloc -> heap big data, low IO access
//Alloca -> stack small data, high IO access
//VLA [size] -> Alloca but with a fixed size at compilation time
#include "dynamic_array.h"

//Note to myself boundaries are never CHECKED !!!
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* vec_init : */
void vec_init(Vector *v, void *values, size_t size){
  if(size > 1 && (size & (size - 1)) != 0){
    fprintf(stderr, "vec_init : error : size must superior to 1 and a power of 2, size is %ld\n", size);
    exit(1);
  }  

  v->size = size | 1; /* set init bit */
  v->cnt = 0;         /* counter set to 0 */
  v->values = values; /* array address set */
}

/* vec_memory_supply : supply memory to the current dynamic array, return 1 if the allocation went well, 0 otherwise */
int vec_memory_supply(Vector *v, size_t current_size, size_t value_size){
  size_t new_size = current_size * 2;

  if(!new_size || value_size > (size_t)-1/new_size)
    return 0; /* overflow */

  void *new_values;
  if(v->size & 1){ /* first time heap allocated */
    new_values = malloc(new_size * value_size);
    if(new_values)
      memcpy(new_values, v->values, current_size * value_size);
  } else {
    new_values = realloc(v->values, new_size * value_size);
  }

  if(!new_values)
    return 0; /* out of mem */

  v->size = new_size;
  v->values = new_values;
  return 1;
}

/* free */
void vec_free(Vector *v){
  if(!(v->size & 1)) /* heap allocated memory ? */
    free(v->values);
  v->values = 0;
}
