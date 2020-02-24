#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mirror(int a,int b){
  return b*10+a;
}

int firstMirrorInE(){
  const double E = 2.718281828459045;
  const int numberOfDigits = 16;

  int* numberMirrors = (int*)calloc(numberOfDigits,sizeof(int));

  for(int i=0;i<numberOfDigits-1;i++){
    int currentDigit = (int)(E*pow(10,i))%10;
    int nextDigit = (int)(E*pow(10,i+1))%10;

    int currentVal = currentDigit*10+nextDigit;

    numberMirrors[i]=mirror(currentDigit,nextDigit);

    for(int j = 0;j < i;j++){
      if(numberMirrors[j]==currentVal){
        return currentVal;
      }
    }
  }
  return 0;
}


int main(void){

  printf("%d\n",firstMirrorInE());

  return 0;
}
