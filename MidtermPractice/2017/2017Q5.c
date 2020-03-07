#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  srand(time(NULL));
  for(int i = 0;i < 100;i++){
    printf("%lf\n",(double)(rand()%19*0.05+0.05));
  }


}
