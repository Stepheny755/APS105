#include <stdio.h>
#include <math.h>

void trapezoidal_integral(double depth, int n, double width, double height, double length, double* integral_result);
double f(double x,double width,double height,double depth);
double getBounds(double width,double height,double depth);
double integral(double a,double b,double* integral_result);

int main(void){

  double width,height,length,sdepth;
  const int n = 10000;

  /*
  printf("Enter the width of the tank (in meters): ");
  scanf("%d",&width);
  printf("Enter the height of the tank (in meters): ");
  scanf("%d",&height);
  printf("Enter the length of the tank (in meters): ");
  scanf("%d",&length);
  printf("Enter the specific depth on the measuring stick (in centimeters): ")
  scanf("%d",&sdepth);
  */

  return 0;
}

double f(double x,double width,double height,double depth){
  return (height/2)*sqrt(1-pow(x,2)/pow((width/2),2))+(height/2)-depth;
}

double getBounds(double width,double height,double depth){
  return (width/2)*sqrt(1-pow((height/2-depth)/(height/2),2));
}

void trapezoidal_integral(double depth, int n, double width, double height, double length, double* integral_result){
  depth/=100;
  double a = 0.0;
  double b = getBounds(width,height,depth);
  double delta = (b-a)/n;
  *integral_result=0;
  for(double i=a+delta;i<b;i+=delta){
    *integral_result+=f(i,width,height,depth)*delta;
    //printf("%lf\n",i);
  }
  *integral_result+=f(a,width,height,depth)*delta/2+f(b,width,height,depth)*delta/2;
}
