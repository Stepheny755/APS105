#include <stdio.h>
#include <stdbool.h>

bool checkLegalInDirection(char board[][26], int n, int row, int col,char colour, int deltaRow, int deltaCol);
bool checkLegalInAllDirections(char board[][26],int n,int row,int col,char colour);

bool positionInBounds(int n, int row, int col);
bool readCharSeq(char* row,char* col);
bool checkMove(char board[][26],int n,char colour,char row,char col);

void getSize(int* n);
void getPlayerColours(char* computer,char* player);
void availableMoves(char board[][26],int n,char colour);
void createBoard(char board[][26],int n);
void printBoard(char board[][26],int n);
void printAvailableMoves(char board[][26],int n);
void flipInDirection(char board[][26],int n,int row,int col,char colour,int deltaRow,int deltaCol);
void flipInAllDirections(char board[][26],int n,int row,int col,char colour);
void makeMove(char board[][26],int n,char colour,char row,char col);

char mainGameLoop(char board[][26],int n,char playerColour,char computerColour);
char getOppositeColour(char colour);
char countWinner(char board[][26],int n);

int countFlips(char board[][26],int n,int row,int col,int colour);
int scoreMoves(char board[][26],int n,char colour,char* row,char* col);

int cToI(char input);
char iToC(int input);
int cToN(char input);
char nToC(int input);

int main(void){

  int n=0;
  char winner;
  char result = ' ',playerColour,computerColour;

  getSize(&n);
  char board[n][26];

  getPlayerColours(&computerColour,&playerColour);

  createBoard(board,n);
  printBoard(board,n);

  winner = mainGameLoop(board,n,playerColour,computerColour);
  if(winner!='D'){
    printf("%c player wins.\n",winner);
  }else{
    printf("Draw!");
  }
  return 0;
}

char mainGameLoop(char board[][26],int n,char playerColour,char computerColour){
  char result = ' ',colour,row,col;
  char cRow,cCol;
  int moveCount = 0;
  while(result == ' '){
    if(moveCount==n*n-4){
      return countWinner(board,n);
    }
    if(playerColour=='B'){
      if(scoreMoves(board,n,playerColour,&cRow,&cCol)>0){
        printf("Enter move for colour %c (RowCol):",playerColour);
        readCharSeq(&row,&col);
        if(!checkMove(board,n,playerColour,row,col)){
          printf("Invalid move.\n");
          return computerColour;
        }else{
          moveCount++;
        }
        printBoard(board,n);
      }else if(moveCount!=n*n-4){
        printf("%c player has no valid move.\n",playerColour);
      }
      if(scoreMoves(board,n,computerColour,&cRow,&cCol)>0){
        printf("Computer places %c at %c%c.\n",computerColour,cRow,cCol);
        makeMove(board,n,computerColour,cRow,cCol);
        printBoard(board,n);
        moveCount++;
      }else if(moveCount!=n*n-4){
        printf("%c player has no valid move.\n",computerColour);
      }
    }else if(playerColour=='W'){
      if(scoreMoves(board,n,computerColour,&cRow,&cCol)>0){
        printf("Computer places %c at %c%c.\n",computerColour,cRow,cCol);
        makeMove(board,n,computerColour,cRow,cCol);
        printBoard(board,n);
        moveCount++;
      }else if(moveCount!=n*n-4){
        printf("%c player has no valid move.\n",computerColour);
      }
      if(scoreMoves(board,n,playerColour,&cRow,&cCol)>0){
        printf("Enter move for colour %c (RowCol):",playerColour);
        readCharSeq(&row,&col);
        if(!checkMove(board,n,playerColour,row,col)){
          printf("Invalid move.\n");
          return computerColour;
        }else{
          moveCount++;
        }
        printBoard(board,n);
      }else if(moveCount!=n*n-4){
        printf("%c player has no valid move.\n",playerColour);
      }
    }
  }
  return result;
}


char countWinner(char board[][26],int n){
  int wCount=0,bCount=0;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      if(board[i][j]=='W'){
        wCount++;
      }else if(board[i][j]=='B'){
        bCount++;
      }
    }
  }
  if(wCount==bCount){
    return 'D';
  }else{
    return (wCount>bCount)?'W':'B';
  }
}

void getPlayerColours(char* computer,char* player){
  printf("Computer plays (B/W): ");
  scanf(" %c",computer);
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

int scoreMoves(char board[][26],int n,char colour,char* row,char* col){
  int maxscore = 0,tempscore = 0,validmoves=0;
  char maxr,maxc;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(board[i][j]=='U'&&checkLegalInAllDirections(board,n,i,j,colour)){
        tempscore = countFlips(board,n,i,j,colour);
        //printf("%c%c: %d\n",iToC(i),iToC(j),tempscore);
        validmoves++;
        //board[i][j]=nToC(tempscore);
        if(tempscore>maxscore){
          maxscore=tempscore;
          maxr=iToC(i);
          maxc=iToC(j);
        }
      }
    }
  }
  *row = maxr;
  *col = maxc;
  return validmoves;
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

bool checkMove(char board[][26],int n,char colour,char row,char col){
  int rowVal = cToI(row),colVal = cToI(col);
  if(board[rowVal][colVal]=='U'&&checkLegalInAllDirections(board,n,rowVal,colVal,colour)){
    flipInAllDirections(board,n,rowVal,colVal,colour);
    board[rowVal][colVal]=colour;
    return true;
  }else{
    return false;
  }
  printBoard(board,n);
}

void makeMove(char board[][26],int n,char colour,char row,char col){
  int rowVal = cToI(row),colVal = cToI(col);
  flipInAllDirections(board,n,rowVal,colVal,colour);
  board[rowVal][colVal]=colour;
}

int countFlips(char board[][26],int n,int row,int col,int colour){
  int counter = 1,cRow=row,cCol=col,totalFlips=0;
  bool flippedAll=false;
  for(int l = -1;l <= 1;l++){
    for(int k = -1;k <= 1;k++){
      if(!(l==0&&k==0)){
        counter = 1;
        while(positionInBounds(n,cRow+l,cCol+k)&&!flippedAll){
          cRow = row+l*counter;
          cCol = col+k*counter;
          if(board[cRow][cCol]==getOppositeColour(colour)){
            totalFlips=counter;
            flippedAll=true;
          }
          counter++;
        }
      }
    }
  }
  return totalFlips;
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
    //printf("%c[cRow,cCol]=[%c,%c]\n",colour,iToC(cRow),iToC(cCol));
    if(board[cRow][cCol]==(colour)){
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

int cToI(char input){
  return (int)(input-'a');
}

char iToC(int input){
  return (char)(97+input);
}

int cToN(char input){
  return (int)(input-'0');
}

char nToC(int input){
  return (char)('0'+input);
}

char getOppositeColour(char colour){
  return (colour=='W')?'B':'W';
}

bool readCharSeq(char* row,char* col){
  scanf(" %c%c",row,col);
  return ((*row=='!')&&(*col=='!'))?false:true;
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
