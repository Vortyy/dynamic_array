#include <stdlib.h>
#include <stdio.h>
#include "dynamic_array.h"

int main(int argc, char **argv){
  if(argc == 1)
    return EXIT_FAILURE;

  size_t size = atol(*++argv);
  int array[size];
  Vector v;
  vec_init(&v, array, size);
  for(int i = 0; i < 3; i++)
    vec_push(&v, i);

  for(int i = 0; i < v.cnt; i++)
    printf("value of v[%d] = %d\n", i, *(v.values + i));

  return EXIT_SUCCESS;
}
