#include <stdio.h>
#include <stdlib.h>

char* preamble(char* str,int n){
  printf("%p\n",str);
  if(str==NULL){
    return NULL;
  }
  char* new = (char*)malloc(sizeof(char)*(n+1));
  int count = 0;
  while(count<n&&str[count]!='\0'){
    new[count]=str[count];
    count++;
  }
  new[count]='\0';
  return new;
}

int main(void){
  char* a; // = "Hello world this is yeet";
  printf("%s %s\n",a,preamble(a,7));
  return 0;
}
