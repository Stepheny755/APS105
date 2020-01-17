#include <stdio.h>

int main(void){

  double inputTemp;
  char tempSystem;

  printf("Input a temperature \n(add F to the end for Fahrenheit and C to the end for celsius): ");
  scanf("%lf%c",&inputTemp,&tempSystem);
  printf("%d\n",(int)tempSystem);
  if((int)tempSystem==67){
    double tempInF=(double)inputTemp*9/5+32;
    printf("%.2lf degrees C = %.2lf degrees F\n",inputTemp,tempInF);
  }else{
    double tempInC=(double)(inputTemp-32)*5/9;
    printf("%.2lf degrees C = %.2lf degrees F\n",tempInC,inputTemp);
  }

  return 0;
}
