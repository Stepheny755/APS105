#include <stdio.h>
#include <stdbool.h>

bool checkLegalInDirection(char board[][26], int n, int row, int col,char colour, int deltaRow, int deltaCol);
bool checkLegalInAllDirections(char board[][26],int n,char row,char col,char color);
bool positionInBounds(int n, int row, int col);
void getSize(int* n);
void availableMoves(char board[][26],int n,char color);
char getOppositeColor(char color);
void printBoard(char board[][26],int n);
void createBoard(char board[][26],int n);
void initialBoardConfiguration(char board[][26],int n);
void checkMove(char board[][26],int n);
bool readCharSeq(char* color,char* row,char* col);
void printAvailableMoves(char board[][26],int n);
int cToI(char input);
char iToC(int input);

int main(void){

  int n=0;
  getSize(&n);

  char board[n][26];
  createBoard(board,n);
  printBoard(board,n);

  initialBoardConfiguration(board,n);
  printBoard(board,n);

  printAvailableMoves(board,n);

  //checkMove(board,n);
  //printf("%s", checkLegalInDirection(board,n,cToI(),cToI(),1,1) ? "true" : "false");

  return 0;
}

void printAvailableMoves(char board[][26],int n){
  printf("Available moves for W:\n");
  availableMoves(board,n,'W');
  printf("Available moves for B:\n");
  availableMoves(board,n,'B');
}

bool positionInBounds(int n,int row,int col){
  //printf("%d %d %d\n",row,col,n);
  return (row<n&&col<n&&row>=0&&col>=0)?true:false;
}

void availableMoves(char board[][26],int n,char color){
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(board[i][j]=='U'&&checkLegalInAllDirections(board,n,i,j,color)){
        printf("%c%c\n",iToC(i),iToC(j));
      }
    }
  }
}

void checkMove(char board[][26],int n){
  printf("Enter a move");
  char color,row,col;
  readCharSeq(&color,&row,&col);
  //printf("%d",checkLegal(board,n,'a','a','B',0,1));
}

bool checkLegalInAllDirections(char board[][26],int n,char row,char col,char color){
  for(int l = -1;l <= 1;l++){
    for(int k = -1;k <= 1;k++){
      if(!(l==0&&k==0)&&checkLegalInDirection(board,n,row,col,color,l,k)){
        return true;
      }
    }
  }
  return false;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col,char colour, int deltaRow, int deltaCol){
  int counter = 1,cRow=row,cCol=col;
  bool oppositeColorBetween = false;
  while(positionInBounds(n,cRow+deltaRow,cCol+deltaCol)){
    cRow = row+deltaRow*counter;
    cCol = col+deltaCol*counter;
    //printf("%c %c %d\n",iToC(cRow),iToC(cCol),counter);
    if(board[cRow][cCol]==getOppositeColor(colour)){
      oppositeColorBetween=true;
    }
    if(board[cRow][cCol]==colour){
      return oppositeColorBetween;
    }else if(board[cRow][cCol]=='U'){
      return false;
    }
    counter++;
  }
  return false;
}

void initialBoardConfiguration(char board[][26],int n){
  printf("Enter board configuration: ");
  char color,row,col;
  while(readCharSeq(&color,&row,&col)){
    board[cToI(col)][cToI(row)]=color;
  }
}

int cToI(char input){
  return (int)(input-'a');
}

char iToC(int input){
  return (char)(97+input);
}

char getOppositeColor(char color){
  return (color=='W')?'B':'W';
}

bool readCharSeq(char* color,char* row,char* col){
  scanf(" %c%c%c",color,row,col);
  return ((*color=='!')&&(*row=='!')&&(*col=='!'))?false:true;
}

void getSize(int* n){
  printf("Enter the board dimension: ");
  scanf("%d",n);
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
        currentPos = board[k-2][i-1];
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
        currentPos = 0;
      }
      printf("%c",currentPos);
    }
    printf("\n");
  }

}
