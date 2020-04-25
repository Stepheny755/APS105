#include <stdio.h>
#include <string.h>

int counte(char* instr){
  int count = 0;
  for(int i = 0;i < strlen(instr);i++){
    if(instr[i]=='e') count++;
  }
  return count;
}



int main(){
  printf("%d",counte("heheheh"));
}
