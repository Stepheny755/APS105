#include <stdio.h>
int main(void){
  double a,b=3.14;
  do{
    int i = 0;//assignment should not happen inside while loop
    printf("Enter a positive integer for offset: \n");
    scanf("%d",&a);
  }while (i<5 && (a<100||a>1));//missing a bracket
  int j;
  for(j=0,j<3,j++){//commas should be semi-colon
    y = b*j%a;//y not initialized
    //cannot modulo dounble values. cast a to integer
    printf("%d\n",y);
  }
  return 0;
}
