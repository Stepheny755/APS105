#include <stdio.h>

int main(void){
  int number,value;
  printf("\nEnter a positive integer: ");
  scanf("%d",&number);
  do{
    value*=10;
    value+=number%10;
    number/=10;
  }while(number>0);
  printf("%d\n",value);
  return 0;
}
