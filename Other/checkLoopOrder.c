#include <stdio.h>

int main(void){

  int board2[n][26];
  int count = 0;
  for(int i=0;i<n;i++){
    for(int k=0;k<n;k++){
      board2[i][k]=count;
      count++;
    }
  }

  for(int i=0;i<n;i++){
    for(int k=0;k<n;k++){
      printf("%d ",board2[k][i]);
    }
    printf("\n");
  }

  return 0;
}
