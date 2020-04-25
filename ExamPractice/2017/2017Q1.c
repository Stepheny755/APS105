#include <stdio.h>
int main(void){
  int j,k;
  int *i=&j;//CTE, cannot assign pointer to address of uninitialized variable. Initialize j

  for(*i=0;*i<10;*i=*i+1){
    scanf("%d",&k);
    printf("%d",(*i)*(*i)*(*i));
  }
}
