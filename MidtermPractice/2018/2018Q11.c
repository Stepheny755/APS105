#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

  srand(time(NULL));
  int size = 1000,maxRandSize = 256;
  int* random = (int*)malloc(sizeof(int)*size);
  int* h = (int*)calloc(maxRandSize,sizeof(int));

  for(int i=0;i<size;i++){
    int tempRand=rand()%maxRandSize;
    *(random+i)=tempRand;
    (*(h+tempRand))++;
  }

  for(int i = 0;i<maxRandSize;i++){
    printf("h[%d]=%d\n",i,*(h+i));
  }

  return 0;
}
