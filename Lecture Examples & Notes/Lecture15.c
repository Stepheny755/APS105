#include <stdio.h>
#include <stdbool.h>

int main(void){

  bool notDone = true;

  int counter = 0;
  int n = 6;
  int input_array[] = {6,5,4,3,2,1};

  while(notDone){
    int nOfSwaps = 0;
    int ptr;

    for(ptr = 0;ptr < n-1;ptr++){
      int leftValue = input_array[ptr];
      int rightValue = input_array[ptr+1];
      if(leftValue>rightValue){
        int temp = input_array[ptr];
        input_array[ptr]=input_array[ptr+1];
        input_array[ptr+1]=temp;
        nOfSwaps++;
      }
    }
    if(nOfSwaps==0){
      notDone=false;
    }else{
      counter++;
    }
  }

  for(int i = 0;i<n;i++){
    printf("%d ",input_array[i]);
  }
  printf("\ncounter = %d\n",counter);

  return 0;
}
