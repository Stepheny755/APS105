#include <stdio.h>

int removeNegatives(int* arr,int size);

int main(void){

  const int SIZE = 8;

  // Potential array inputs.
  int allNegatives[] = {-3, -1, -5, -9, -10, -6, -7, -3};
  int adjacentNegatives[] = {-3, -1, 5, -9, -10, 6, -7, -3};
  int alternatingNegatives[] = {3, -1, 5, -9, 10, -6, 7, -3};

  // Pick an input.
  int *array = adjacentNegatives;

  int numRemoved = removeNegatives(array, SIZE);
  printf("%d negatives removed.\n", numRemoved);
  for(int i = 0; i < SIZE; i++) {
    printf("array[%d]: %d\n", i, array[i]);
  }
}

int removeNegatives(int* arr,int size){
  int lastIndex = 0,numNegatives=0;
  for(int i = 0;i < size;i++){
    if(*(arr+i)<0){
      *(arr+i)=0;
      numNegatives++;
    }else{
      int temp = *(arr+i);//arr[i]=*(arr+i)
      *(arr+i)=0;
      *(arr+lastIndex)=temp;
      lastIndex++;
    }
  }
  return numNegatives;
}
