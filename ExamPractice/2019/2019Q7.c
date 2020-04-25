#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double D2R = 3.1415926535 / 180.0;

typedef struct rectV{
  double xcoord;
  double ycoord;
}RectCoor;

typedef struct polarC{
  double radius;
  double theta;
}PolarCoor;

RectCoor polToRec(PolarCoor polin){
  RectCoor* rectout = (RectCoor*)malloc(sizeof(RectCoor));
  rectout->xcoord=polin.radius*cos(polin.theta*D2R);
  rectout->ycoord=polin.radius*sin(polin.theta*D2R);
  return *rectout;
}

int main(){
  PolarCoor* temp = (PolarCoor*)malloc(sizeof(PolarCoor));
  temp->radius = 5;
  temp->theta = 45;
  RectCoor new = polToRec(*temp);
  printf("%lf %lf\n",new.xcoord,new.ycoord);



}
