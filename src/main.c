#include <stdlib.h>
#include <stdio.h>
#include "dynamic_array.h"

int main(int argc, char **argv){
  if(argc == 1)
    return EXIT_FAILURE;

  int size = atoi(*++argv);
  int array[size];

  Vector v;
  int i = 3;
  vec_init(&v, array, size);

  for(int i = 0; i < 26; i++){
    vec_push(&v, i, int);
  }
  
  for(int i = 0; i < v.cnt; i++) 
    printf("value of v[%d] = %d\n", i, vec_get_value(&v, i, int));

  return EXIT_SUCCESS;
}
