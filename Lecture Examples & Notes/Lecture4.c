#include <stdio.h>
#include <stdbool.h>

int main(void){

  double inputInches,outputCMs;
  const double InchesToCMs = 2.54;

  printf("Enter the number of inches to convert: ");
  scanf("%lf",&inputInches);

  outputCMs = inputInches * InchesToCMs;
  printf("Number of centimeters: %.2lf\n",outputCMs);
  
  return 0;
}
