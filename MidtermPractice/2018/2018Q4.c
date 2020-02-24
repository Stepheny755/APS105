#include <stdio.h>

int mostSignificantDigit(int val){
  int sigDig = 0;
  while(val>0){
    sigDig = val%10;
    val/=10;
  }
  return sigDig;
}

int main(){

  printf("%d\n",mostSignificantDigit(987654321));


  return 0;
}
