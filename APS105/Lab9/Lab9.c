#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rawRecipes.h"

typdef struct ingredient

char* shiftStr(char* str){
  char* shifted = (char*)malloc(sizeof(char)*60);
  strcpy(shifted,str+1);
  return shifted;
}

int main(void){

  int i = 0;
  char* s = rawRecipes[i];
  /*
  while(s!=""){
    printf("%s\n",s);
    printf("%s\n",shiftStr(s));
    i++;
    s= rawRecipes[i];
  }
  */
  printf("%s\n",s);
  printf("%s\n",shiftStr("hi there\0"));

  return 0;
}
