#include <stdio.h>
#include <stdbool.h>

bool checkLegalInDirection(char board[][26], int n, int row, int col,char colour, int deltaRow, int deltaCol);
bool checkLegalInAllDirections(char board[][26],int n,int row,int col,char colour);

bool positionInBounds(int n, int row, int col);
bool readCharSeq(char* colour,char* row,char* col);

void getSize(int* n);
void getPlayerColours(char* computer,char* player);
void availableMoves(char board[][26],int n,char colour);
void createBoard(char board[][26],int n);
void initialBoardConfiguration(char board[][26],int n);
void printBoard(char board[][26],int n);
void checkMove(char board[][26],int n);
void printAvailableMoves(char board[][26],int n);

void flipInDirection(char board[][26],int n,int row,int col,char colour,int deltaRow,int deltaCol);
void flipInAllDirections(char board[][26],int n,int row,int col,char colour);

char mainGameLogic(int n);
char getOppositeColour(char colour);

int cToI(char input);
char iToC(int input);

int main(void){

  int n=0;
  char victor;
  getSize(&n);

  victor = mainGameLogic(n);
  //printf("%c")
  return 0;
}

char mainGameLogic(int n){

  char board[n][26];
  char result = ' ',playerColour,computerColour;
  createBoard(board,n);

  getPlayerColours(&computerColour,&playerColour);

  printBoard(board,n);

  //initialBoardConfiguration(board,n);
  //printBoard(board,n);
  //printAvailableMoves(board,n);



  checkMove(board,n);
  return result;
}

void getPlayerColours(char* computer,char* player){
  printf("Computer plays (B/W): ");
  scanf("%c",computer);
  *player = getOppositeColour(*computer);
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

void availableMoves(char board[][26],int n,char colour){
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(board[i][j]=='U'&&checkLegalInAllDirections(board,n,i,j,colour)){
        printf("%c%c\n",iToC(i),iToC(j));
      }
    }
  }
}

void checkMove(char board[][26],int n){
  printf("Enter a move:\n");
  char colour,row,col;
  readCharSeq(&colour,&row,&col);
  int rowVal = cToI(row),colVal = cToI(col);
  if(board[rowVal][colVal]=='U'&&checkLegalInAllDirections(board,n,rowVal,colVal,colour)){
    printf("Valid move.\n");
    flipInAllDirections(board,n,rowVal,colVal,colour);
    board[rowVal][colVal]=colour;
  }else{
    printf("Invalid move.\n");
  }
  printBoard(board,n);
}

void flipInAllDirections(char board[][26],int n,int row,int col,char colour){
  for(int l = -1;l <= 1;l++){
    for(int k = -1;k <= 1;k++){
      if(!(l==0&&k==0)&&checkLegalInDirection(board,n,row,col,colour,l,k)){
        //printf("%c%c legal in direction %d,%d\n",iToC(row),iToC(col),l,k);
        flipInDirection(board,n,row,col,colour,l,k);
      }
    }
  }
}

void flipInDirection(char board[][26],int n,int row,int col,char colour,int deltaRow,int deltaCol){
  int counter = 1,cRow=row,cCol=col;
  bool flippedAll = false;
  while(positionInBounds(n,cRow+deltaRow,cCol+deltaCol)&&!flippedAll){
    cRow = row+deltaRow*counter;
    cCol = col+deltaCol*counter;
    if(board[cRow][cCol]==getOppositeColour(colour)){
      flippedAll=true;
    }
    board[cRow][cCol]=colour;
    counter++;
  }
}

bool checkLegalInAllDirections(char board[][26],int n,int row,int col,char colour){
  for(int l = -1;l <= 1;l++){
    for(int k = -1;k <= 1;k++){
      if(!(l==0&&k==0)&&checkLegalInDirection(board,n,row,col,colour,l,k)){
        //printf("%c%c legal in direction %d,%d\n",iToC(row),iToC(col),l,k);
        return true;
      }
    }
  }
  return false;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col,char colour, int deltaRow, int deltaCol){
  int counter = 1,cRow=row,cCol=col;
  bool oppositecolourBetween = false;
  while(positionInBounds(n,cRow+deltaRow,cCol+deltaCol)){
    cRow = row+deltaRow*counter;
    cCol = col+deltaCol*counter;
    //printf("%d %d at %c%c board=%c counter: %d\n",row,col,iToC(cRow),iToC(cCol),(board[cRow][cCol]),counter);
    if(board[cRow][cCol]==getOppositeColour(colour)){
      oppositecolourBetween=true;
    }else if(board[cRow][cCol]==colour){
      return oppositecolourBetween;
    }else if(board[cRow][cCol]=='U'){
      return false;
    }
    counter++;
  }
  return false;
}

void initialBoardConfiguration(char board[][26],int n){
  printf("Enter board configuration:\n");
  char colour,row,col;
  while(readCharSeq(&colour,&row,&col)){
    board[cToI(row)][cToI(col)]=colour;
  }
}

int cToI(char input){
  return (int)(input-'a');
}

char iToC(int input){
  return (char)(97+input);
}

char getOppositeColour(char colour){
  return (colour=='W')?'B':'W';
}

bool readCharSeq(char* colour,char* row,char* col){
  scanf(" %c%c%c",colour,row,col);
  return ((*colour=='!')&&(*row=='!')&&(*col=='!'))?false:true;
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
        currentPos = board[i-1][k-2];
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
