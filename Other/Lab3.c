#include <stdio.h>
/*
int getIndexFromChar(char *charCode,char input){
  if(*source==)


}
*/
int main(void){

  for(int i = 0;i < 8;i++){
    printf("%d",i);
  }
  printf("\n");
  for(int i = 0;i < 8;++i){
    printf("%d",i);
  }

  char charCode[12] = {'k','b','r','o','e','g','u','v','y','w','l','s'};
  char colorCode[12][6] = {"Black","Brown","Red","Orange","Yellow","Green","Blue","Violet","Grey","White","Gold","Silver"};
  char input = 'b';

  //printf("%d",getIndexFromChar(&charCode,input))

  printf("Please enter the 1st band of resistor 1:\n");

  printf("Please enter the 2nd band of resistor 1:\n");

  printf("Please enter the multiplier band of resistor 1:\n");

  printf("Please enter the tolerance band of resistor 1:\n");

  printf("Please enter the 1st band of resistor 2:\n");

  printf("Please enter the 2nd band of resistor 2:\n");

  printf("Please enter the multiplier band of resistor 2:\n");

  printf("Please enter the tolerance band of resistor 2:\n");


  return 0;
}
