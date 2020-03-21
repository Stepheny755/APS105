#include <stdio.h>

int main(){



}

int seqSearch(int list[],int listlength,int item){
  for(int i = 0;i < listlength;i++){
    if(list[i]==item){
      return i;
    }
  }
}
