#include <stdio.h>

int correct(int a){
  int b;
  if(a==0){
    b=0;
  }else{
    b=a%2 + 10*correct(a/2);
  }
  return b;
}
//above function returns binary representation of an integer

int main(void){
  int number;
  number = correct(121);
  printf("The correct value for 121 is %d\n",correct(121));
  return 0;
}

1111001
