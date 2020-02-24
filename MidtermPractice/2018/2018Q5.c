#include <stdio.h>

int main(void){
  int numApples = 10;
  int leftover = (numApples%5<numApples%3) ? numApples%5 : numApples%3;
  printf("%d\n",leftover);
  return 0;
}
