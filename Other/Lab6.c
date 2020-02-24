#include <stdio.h>
#include "lab6.h"

//function prototyping

//print the board array of size (1,rows-1)x(1,cols-1)
void printArray(int rows,int cols,char array[rows][cols]);

//print line of given length;
void printLine(int length);

//calculate the number of mines around a given x-y coordinate
int getNumberofMines(int x,int y,int rows,int cols,char array[rows][cols]);

int main(void){

  int m,n;
  double p;

  printf("Enter the number of rows: ");
  scanf("%d",&m);
  printf("Enter the number of columns: ");
  scanf("%d",&n);
  printf("Enter the probability p value: ");
  scanf("%lf",&p);

  int rows=m+2,cols=n+2;

  char board[rows][cols];
  /*
  int** board = (int**)malloc(sizeof(int*)*rows);
  for(int i = 0;i < rows;i++){
    board[i]=(int*)malloc(sizeof(int)*cols);
  }
  */
  for(int i = 0;i < rows;i++){
    for(int j = 0;j < cols;j++){
      board[i][j]=0;
    }
  }

  for(int i = 1;i < rows-1;i++){
    for(int j = 1;j < cols-1;j++){
      double probability=rand();
      if(probability<p){
        board[i][j]='*';
      }else{
        board[i][j]='.';
      }
    }
  }
  printLine(cols);
  printArray(rows,cols,board);

  for(int yval = 1;yval < rows-1;yval++){
    for(int xval = 1;xval < cols-1;xval++){
      if(board[yval][xval]=='.'){
        //printf("%d,%d",yval,xval);
        board[yval][xval]=(char)getNumberofMines(xval,yval,rows,cols,board);
      }
    }
  }
  printLine(cols);
  printArray(rows,cols,board);
  printLine(cols);

  return 0;
}

void printLine(int length){
  for(int i = 0;i<((length-2)*2)-1;i++){
    printf("-");
  }
  printf("\n");
}

//print the board array of size (1,rows-1)x(1,cols-1)
void printArray(int rows,int cols,char array[rows][cols]){
  for(int i = 1;i < rows-1;i++){
    for(int j = 1;j < cols-1;j++){
      if(array[i][j]=='*'||array[i][j]=='.'){
        printf("%c ",(char)array[i][j]);
      }else{
        printf("%c ",array[i][j]+'0');
      }
    }
    printf("\n");
  }
}

//calculate the number of mines around a given x-y coordinate
int getNumberofMines(int x,int y,int rows,int cols,char array[rows][cols]){
  int numberOfMines=0;
  for(int yval = y-1;yval<=y+1;yval++){
    for(int xval = x-1;xval<=x+1;xval++){
      //printf("\n(x,y)=(%d,%d)",yval,xval);
      if(array[yval][xval]=='*'){
        numberOfMines++;
      }
    }
  }
  //printf("number of mines: %d\n",numberOfMines);
  return numberOfMines;
}
