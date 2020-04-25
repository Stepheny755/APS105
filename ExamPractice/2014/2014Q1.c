#include <stdio.h>
//original, incorrect answer
int main(){
  int x = 50;
  int xbig=30;
  while(x>xBig)
    x-=2;
    xBig++;

  printf("The value of x is %d");
}

//correct answer
//while loop require brace brackets to indicate the scope. By including the brackets, the line "xBig++" is included in the while loop
int main(){
  int x = 50;
  int xbig=30;
  while(x>xBig){
    x-=2;
    xBig++;
  }
  printf("The value of x is %d");
}
