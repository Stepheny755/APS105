#include <stdio.h>

int findMaximumValue(int list[],size){
  int maxVal=0;
  for(int i = 0;i < size;i++){
    if(maxVal<list[i]){
      maxVal = list[i];
    }
  }
  return maxVal;
}

int main(void){



  return 0;
}
