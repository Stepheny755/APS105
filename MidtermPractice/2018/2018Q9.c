#include <stdio.h>

double dotProduct(double a[],double b[],int size){
  double product=0.0;
  for(int i = 0;i<size;i++){
    product+=a[i]*b[i];
    //printf("%lf\n",product);
  }
  return product;
}

int main(){

  double music[] = {0,0.707,1,0.707,0,-0.707,-1,-0.707,0};
  double filter[] = {1,0,-1,0,2,0,-1,0,1};
  //double test[]={1,1,1,1,1,1,1,1,1};

  printf("Result = %lf\n",dotProduct(music,filter,9));

  return 0;
}
