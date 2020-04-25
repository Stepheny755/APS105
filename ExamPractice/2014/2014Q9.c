#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double newtonSquareRoot(double x){
  double zg=x/2,zn=-1;
  do{
    zn = zg - (zg*zg-x)/(2*zg);
    printf("%lf\n",fabs(zn-zg));
    if(fabs(zn-zg)<=1e-3){
      return zn;
    }
    zg = zn;
  }while(1);
}

int main(void){
  printf("sqrt: %lf\n",newtonSquareRoot(25122253));

}
