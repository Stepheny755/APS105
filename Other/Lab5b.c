#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void trapezoidal_integral(double depth, int n, double width, double height, double length, double* integral_result);
double flower(double x,double width,double height,double depth);
double fupper(double x,double width,double height,double depth);
double getBounds(double width,double height,double depth);
double integral(double a,double b,double* integral_result);

int main(void){

  double width,height,length,sdepth;
  double volume = 0;
  const int n = 10000;


  printf("Enter the width of the tank (in meters): ");
  scanf("%lf",&width);
  printf("Enter the height of the tank (in meters): ");
  scanf("%lf",&height);
  printf("Enter the length of the tank (in meters): ");
  scanf("%lf",&length);
  printf("Enter the specific depth on the measuring stick (in centimeters): ");
  scanf("%lf",&sdepth);

  trapezoidal_integral(sdepth,n,width,height,length,&volume);
  printf("Depth %d cm : Volume %.2lf cubic meters\n",(int)sdepth,volume);
  return 0;
}

double fupper(double x,double width,double height,double depth){
  return (height/2)*sqrt(1-pow(x,2)/pow((width/2),2))+(height/2)-depth;
}

double flower(double x,double width,double height,double depth){
  return -(height/2)*sqrt(1-pow(x,2)/pow((width/2),2))+(height/2)-depth;
}

double getBounds(double width,double height,double depth){
  return (width/2)*sqrt(1-pow((height/2-depth)/(height/2),2));
}

void trapezoidal_integral(double depth, int n, double width, double height, double length, double* integral_result){
  depth/=100;
  double a = -getBounds(width,height,depth);
  double b = getBounds(width,height,depth);
  double bVol=0.0,tVol=0.0;
  //printf("%lf",a);
  double delta = (b-a)/n;
  *integral_result=0;
  if(depth>=height/2){
    tVol = M_PI*(width/2)*(height/2);
    for(double i=a+delta;i<b;i+=delta){
      tVol-=fupper(i,width,height,depth)*delta;
      //printf("tvol: %lf\n",tVol);
    }
    tVol+=fupper(a,width,height,depth)*delta/2+fupper(b,width,height,depth)*delta/2;
  }else{
    for(double i=a+delta;i<b;i+=delta){
      bVol+=flower(i,width,height,depth)*delta;
    }
    bVol+=flower(a,width,height,depth)*delta/2+flower(b,width,height,depth)*delta/2;
  }
  if(bVol<=0){
    bVol*=-1;
  }
  if(tVol<=0){
    tVol*=-1;
  }
  *integral_result = (bVol+tVol)*length;
}
