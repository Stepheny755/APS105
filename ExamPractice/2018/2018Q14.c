#include <stdio.h>

int findIndex(char* string,char c){
  int n = 0;
  while(*string!=c&&*string!='\0'){
    string = string + 1;
    ++n;
  }
  if(*string == '\0')
    return -1;
  return n;
}

int recursiveFindIndex(char* string,char c,int i){
  if(string[i]==c){
    return i;
  }if(string[i]=='\0'){
    return -1;
  }else{
    return recursiveFindIndex(string,c,i+1);
  }
}

int main(void){
  printf("%d\n",recursiveFindIndex("hello",'o',0));
  return 0;
}
