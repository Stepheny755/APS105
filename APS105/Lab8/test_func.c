#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int getDistance(int ax,int ay,int bx,int by){
  return (ax-bx)*((ax>bx)?1:-1)+(ay-by)*((ay>by)?1:-1);
}
/*
int getAvailableMoves(char board[][26],int n,char colour,char* rows,char* cols){
  int size = 0,maxsize = n*n-4;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(board[i][j]=='U'&&checkLegalInAllDirections(board,n,i,j,colour)){
        rows[size]=iToC(i);
        cols[size]=iToC(j);
        size++;
      }
    }
  }
  rows[size]='\0';
  cols[size]='\0';
  return size;
}
*/
bool isCornerClose(char board[][26],int n,int ax,int ay){
  n = n-1;
  if((getDistance(ax,ay,0,0)==1||(ax==1&&ay==1))&&board[0][0]=='U'){
    return true;
  }
  if((getDistance(ax,ay,0,n)==1||(ax==1&&ay==n-1))&&board[0][n]=='U'){
    return true;
  }
  if((getDistance(ax,ay,n,0)==1||(ax==n-1&&ay==1))&&board[n][0]=='U'){
    return true;
  }
  if((getDistance(ax,ay,n,n)==1||(ax==n-1&&ay==n-1))&&board[n][n]=='U'){
    return true;
  }
  return false;
}

void createBoard(char board[][26],int n){
  for(int i = 0;i < n;i++){
    for(int k = 0;k < n;k++){
      board[i][k]='U';
    }
  }
  board[n/2-1][n/2-1]='W';
  board[n/2][n/2]='W';
  board[n/2][n/2-1]='B';
  board[n/2-1][n/2]='B';
}

void printBoard(char board[][26],int n){
  int row=97,col=97;

  for(int i = 0;i < n+1;i++){
    for(int k = 0;k < n+2;k++){
      char currentPos = ' ';
      if(i>0&&k>1){
        currentPos = board[i-1][k-2];
        //printf("add @ %d,%d = %p\n",i-1,k-2,&board[i-1][k-2]);
      }

      if(i==0&&k>1){
        currentPos=(char)col;
        col++;
      }else if(i==0&&k==0){
        currentPos = ' ';
      }
      if(k==0&&i>0){
        currentPos=(char)row;
        row++;
      }else if(k==1){
        currentPos = ' ';
      }
      printf("%c",currentPos);
    }
    printf("\n");
  }

}

int calculateElapsedTime(clock_t start){
  clock_t current = clock();
  double duration = (double)(current-start)/CLOCKS_PER_SEC;
  duration*=1000;
  return (int) duration;
}

int main(void){
/*
  int n = 8;
  char board[n][26];
  createBoard(board,n);
  board[0][0]='W';
  printBoard(board,n);
  for(int i = 0;i < n;i++){
    for(int k = 0;k < n;k++){
      printf("%d",(isCornerClose(board,n,i,k))?1:0);
    }
    printf("\n");
  }
*/
  clock_t begin = clock();

  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      printf("%d%d\n",i,j);
    }
  }

 printf("time: %d\n",calculateElapsedTime(begin));

  return 0;
}
