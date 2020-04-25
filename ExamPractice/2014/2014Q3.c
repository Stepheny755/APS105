#include <math.h>
#include <stdio.h>
//original incorrect code
void separate(double number, char* signPtr,int *wholePtr, double* fracPtr){
  double magnitude;
  if(number < 0){
    *singPtr = '-';
  }else if(number==0){
    *signPtr = ' ';
  }else{
    *signPtr = '+';
  }
  magnitude = fabs(number);
  wholePtr = floor(magnitude);
  fracPtr = magnitude-wholePtr;
}

//corrected code
void separate(double number, char* signPtr,int *wholePtr, double* fracPtr){
  double magnitude;
  if(number < 0){
    *singPtr = '-';
  }else if(number==0){
    *signPtr = ' ';
  }else{
    *signPtr = '+';
  }
  magnitude = fabs(number);
  *wholePtr = floor(magnitude);
  *fracPtr =  magnitude-*wholePtr;
}
