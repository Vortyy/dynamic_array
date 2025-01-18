#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dynamic_array.h"

int main(int argc, char **argv){
  if(argc == 1)
    return EXIT_FAILURE;

  srand(time(NULL));

  int size = atoi(*++argv);
  int array[size];

  Vector v;
  vec_init(&v, array, size);

  for(int i = 0; i < 26; i++){
    vec_push(&v, rand() % 100);
  }
  
  for(int i = 0; i < v.cnt; i++) 
    printf("value of v[%d] = %d\n", i, vec_get(&v, i, int));

  return EXIT_SUCCESS;
}
