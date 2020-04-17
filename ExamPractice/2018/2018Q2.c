#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

  srand(time(NULL));
  int randomChoice = (rand()%151)*2-150;
  printf("%d\n",randomChoice);

}
