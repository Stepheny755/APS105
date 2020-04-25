#include <stdio.h>

int main(void){
  int* x;
  int result;

  *x=0;
  result = *x;
  printf("%d",result);
  return 0;
}

//memory that pointer x points to is unallocated
