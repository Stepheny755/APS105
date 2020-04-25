#include <stdio.h>
#include <stdbool.h>


bool isEven(int a){
  return (a%2==0);
}


void sortOddEven(int input[],int size){
  bool sorted = false;
  int bcount = 0,tcount = size;
  int lswap=0,rswap=0;
  while(!sorted){
    if(isEven(input[bcount])){
      lswap = bcount;
    }else{
      bcount++;
    }
    if(!isEven(input[tcount])){
      rswap = tcount;
    }else{
      tcount--;
    }
    if(lswap!=-1&&rswap!=-1){
      int temp = input[lswap];
      input[lswap]=input[rswap];
      input[rswap]=temp;
      lswap=-1;
      rswap=-1;
    }
    if(bcount>=tcount){
      sorted=true;
    }
  }
}

int main(void){
  int arr[] = {1,4,6,5,9,3,8,2};
  sortOddEven(arr,8);
  for(int i = 0;i < 8;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
