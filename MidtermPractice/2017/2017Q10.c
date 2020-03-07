#include <stdio.h>

bool whichBiggerAndHowMuch(int vala,int valb,int* diff){
  *diff = ((vala-valb)<0)?(valb-vala):(vala-valb);
  return (vala>valb)?true:false;
}
