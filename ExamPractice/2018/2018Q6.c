#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int stringLength(char* str){
  char pos = *str;
  int count = 0;
  while(pos!='\0'){
    count++;
    pos = *(str+count);
  }
  return count;
}
*/
int stringLength(char* str){
  if(str==NULL){
    return 0;
  }
  int count = 0;
  while(*(str+count)!='\0'){
    count++;
  }
  return count;
}

int main(void){
  char* a =  "Hello World yeet";
  printf("Length of (%s) is %d\n",a,stringLength(a));
}
