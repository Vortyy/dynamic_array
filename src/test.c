#include <stdio.h>
//snippet that give us which C version you're using
int main(){
  
  if (__STDC_VERSION__ >= 201710L)
      printf("We are using C17!\n");
  else if (__STDC_VERSION__ >= 201112L)
      printf("We are using C11!\n");
  else if (__STDC_VERSION__ >= 199901L)
      printf("We are using C99!\n");
  else
      printf("We are using C89/C90!\n");

  return 0;
}
