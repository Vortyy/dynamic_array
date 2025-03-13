#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dynamic_array.h"

int main(int argc, char **argv){
  if(argc == 1){
    printf("error: must set starting size\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  int size = atoi(*++argv); /* arg 1 set the size of the original stack buffer */
  int array[size];

  Vector v; 
  vec_init(&v, array, size);

  for(int i = 0; i < 26; i++){
    vec_push(&v, rand() % 100); /* push random number more that size of the base array */
  }
  
  for(int i = 0; i < v.cnt; i++) 
    printf("value of v[%d] = %d\n", i, vec_get(&v, i, int)); /* print values inside the Vector v */

  return EXIT_SUCCESS;
}
