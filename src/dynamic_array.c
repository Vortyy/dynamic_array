// objectif library static dynamic with a dynamic array implementation (ArrayList java) 

//Malloc -> heap big data, low IO access
//Alloca -> stack small data, high IO access
//VLA [size] -> Alloca but with a fixed size at compilation time
#include "dynamic_array.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* vec_init : */
void vec_init(Vector *v, int *values, size_t size){
  if(size > 1 && (size & (size - 1)) != 0){
    fprintf(stderr, "vec_init : error : size must superior to 1 and a power of 2, size is %ld\n", size);
    exit(1);
  }  

  v->size = size | 1; /* set init bit */
  v->cnt = 0;         /* counter set to 0 */
  v->values = values; /* array address set */
}

/* push : */
int vec_push(Vector *v, int t){
  size_t current_size = v->size & ~(size_t)1;
  if(v->cnt == current_size){
    size_t value_size = sizeof(v->values[0]);
    size_t new_size = current_size * 2;

    if(!new_size || value_size > (size_t)-1/new_size)
      return 0; /* overflow */

    void *new_values;
    if(v->size & 1){
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
  }
  v->values[v->cnt++] = t;
  return 1;
}

/* free */
void vec_free(Vector *v){
  if(!(v->size & 1)) /* heap allocated memory ? */
    free(v->values);
  v->values = 0;
}

/*int main(int argc, char *argv[]){*/
/*  if(argc == 1)*/
/*    return EXIT_FAILURE;*/
/**/
/*  size_t size = atol(*++argv);*/
/*  int array[size];*/
/*  Vector v;*/
/*  vec_init(&v, array, size);*/
/*  for(int i = 0; i < 3; i++)*/
/*    vec_push(&v, i);*/
/**/
/*  for(int i = 0; i < v.cnt; i++)*/
/*    printf("value of v[%d] = %d\n", i, *(v.values + i));*/
/**/
/*  return EXIT_SUCCESS;*/
/*}*/
