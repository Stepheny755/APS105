#include <stdio.h>
#include <math.h>

void getInput(int *outFeet, int *outInches);
void printOutput(int feet, int inches, int metres, int centimetres);
void convert(int feet, int inches, int *outMetres, int *outCentimetres);

int main(){
  int inputFeet,inputInches,outputMetres,outputCentimetres;
  getInput(&inputFeet,&inputInches);
  convert(inputFeet,inputInches,&outputMetres,&outputCentimetres);
  printOutput(inputFeet,inputInches,outputMetres,outputCentimetres);

  return 0;
}

void getInput(int *outFeet, int *outInches){
  printf("Please enter the feet and inches to convert: ");
  scanf("%d %d",outFeet,outInches);
}

void printOutput(int feet, int inches, int metres, int centimetres){
  printf("%d feet %d inches is %d metres and %d centimeters",feet,inches,metres,centimetres);
}

void convert(int feet, int inches, int *outMetres, int *outCentimetres){
  double totalFeet = feet+inches/12.0;
  double totalMetres = totalFeet*0.3048;

  *outMetres = (int)totalMetres;
  *outCentimetres = rint((totalMetres-*outMetres)*100);
}
