#include <stdio.h>
#include <ctype.h>

int indexOf(char searchKey,char* array,int size);

int main(void){

  char resistor1Band1,resistor1Band2,resistor1Multiplier,resistor1Tolerance;
  char resistor2Band1,resistor2Band2,resistor2Multiplier,resistor2Tolerance;
  double resistor1Value=0.0,resistor2Value=0.0;
  const int numberOfCodes = 12;

  char colourCodes[] = {'k','b','r','o','e','g','u','v','y','w','l','s'};

  printf("Please enter the 1st band of resistor 1:\n");
  scanf(" %c",&resistor1Band1);
  resistor1Value+=indexOf(resistor1Band1,colourCodes,numberOfCodes)*10;
  printf("Please enter the 2nd band of resistor 1:\n");
  scanf(" %c",&resistor1Band2);
  resistor1Value+=indexOf(resistor1Band2,colourCodes,numberOfCodes);
  printf("Please enter the multiplier band of resistor 1:\n");
  scanf(" %c",&resistor1Multiplier);

  printf("Please enter the tolerance band of resistor 1:\n");
  scanf(" %c",&resistor1Tolerance);

  printf("Please enter the 1st band of resistor 2:\n");
  scanf(" %c",&resistor2Band1);

  printf("Please enter the 2nd band of resistor 2:\n");
  scanf(" %c",&resistor2Band2);

  printf("Please enter the multiplier band of resistor 2:\n");
  scanf(" %c",&resistor2Multiplier);

  printf("Please enter the tolerance band of resistor 2:\n");
  scanf(" %c",&resistor2Tolerance);

  printf("%lf",resistor1Value);

}

int indexOf(char searchKey,char* array,int size){
  if(tolower(searchKey)==array[size]){
    return size;
  }else{
    return indexOf(searchKey,array,size-1);
  }
}
