#include <stdio.h>

int secondLargest(int *arr,int size){
  int largestVal = 0,secondLargestVal=0,secondLargestIndex=-1;
  for(int i = 0;i < size;i++){
    if(largestVal<*(arr+i)){
      largestVal = *(arr+i);
    }
  }
  for(int i = 0;i < size;i++){
    if(*(arr+i)>secondLargestVal&&*(arr+i)<largestVal){
      secondLargestVal = *(arr+i);
      secondLargestIndex=i;
    }
  }
  return secondLargestIndex;
}

int main(void){

  int list[] = {3, 8, 3, 5, 9, 8, 2, 3, 8};// {3,9,7,5,9,8,2,4,9};

  printf("%d\n",secondLargest(list,sizeof(list)/sizeof(list[0])));

  return 0;
}
