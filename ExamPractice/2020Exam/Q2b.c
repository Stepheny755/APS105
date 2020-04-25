#include <stdio.h>

int main(){
  int q[7]={0,3,6,9,12,15,18};
  int *b = &q[3];
  int **a = &b;
  printf("%d\n",*(&(**a)+2));//points to 15, the element at index 5 of array q
}
