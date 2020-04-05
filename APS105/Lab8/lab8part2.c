#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <sys/resource.h>
#include "lab8part2lib.h"

bool checkLegalInDirection(char board[][26], int n, int row, int col,char colour, int deltaRow, int deltaCol);
bool checkLegalInAllDirections(char board[][26],int n,int row,int col,char colour);

bool positionInBounds(int n, int row, int col);
bool readCharSeq(char* row,char* col);
bool checkMove(char board[][26],int n,char colour,char row,char col);
bool isCornerClose(char board[][26],int n,int ax,int ay);

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
char testGameLoop(char board[][26],int n,char playerColour,char computerColour);
char getOppositeColour(char colour);
char countWinner(char board[][26],int n);

int countFlips(char board[][26],int n,int row,int col,int colour);
int scoreMoves(char board[][26],int n,char colour,char* row,char* col);
int scoreBotMoves(char board[][26],int n,int moveCount,char colour,char* row,char* col);
int getAvailableMoves(char board[][26],int n,char colour,char* rows,char* cols);
int getNumAvailableMoves(char board[][26],int n,char colour);

int minimax(char board[][26],int n,int depth,int moveCount,clock_t processingTime,int numMoves,int a,int b,char playerColour,char colour);
int makeDecision(char board[][26],int n,int depth,int moveCount,int a,int b,char colour,char* row,char* col);

int nextGuess(int alpha,int beta,int numMoves);
int getDistance(int ax,int ay,int bx,int by);
int calculateElapsedTime(clock_t start);

int cToI(char input);
char iToC(int input);
int cToN(char input);
char nToC(int input);

int max(int a,int b);

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
      if(scoreBotMoves(board,n,moveCount,computerColour,&cRow,&cCol)>0){
        printf("Computer places %c at %c%c.\n",computerColour,cRow,cCol);
        makeMove(board,n,computerColour,cRow,cCol);
        printBoard(board,n);
        moveCount++;
      }else if(moveCount!=n*n-4){
        printf("%c player has no valid move.\n",computerColour);
      }
    }else if(playerColour=='W'){
      if(scoreBotMoves(board,n,moveCount,computerColour,&cRow,&cCol)>0){
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

char testGameLoop(char board[][26],int n,char playerColour,char computerColour){
  char result = ' ',colour,row,col;
  char cRow,cCol;
  int botMoves = 0,compMoves=0;
  int moveCount = botMoves+compMoves;
  bool pHasMove=true,cHasMove=true;

  struct rusage usage; // a structure to hold "resource usage" (including time)
  struct timeval start, end; // will hold the start and end times

  while(result == ' '){
    if(moveCount==n*n-4){
      return countWinner(board,n);
    }

    moveCount = botMoves+compMoves;
    if(moveCount >= 1){
      //break;
    }
    if(playerColour=='B'){

      clock_t begin = clock();

      if(scoreBotMoves(board,n,moveCount,playerColour,&cRow,&cCol)>0){
        printf("Bot places %c at %c%c.\n",playerColour,cRow,cCol);
        makeMove(board,n,playerColour,cRow,cCol);
        printBoard(board,n);
        botMoves++;
      }else if(moveCount!=n*n-4){
        pHasMove=false;
        printf("%c player has no valid move.\n",playerColour);
        //return computerColour;
      }

      clock_t end = clock();
      double duration = (double)(end-begin)/CLOCKS_PER_SEC;
      printf("Bot move ran in %lf seconds.\n",duration);

      if(scoreMoves(board,n,computerColour,&cRow,&cCol)>0){
        int tr,tc;
        findSmartestMove(board, n, computerColour, &tr, &tc);
        printf("Testing AI move (row, col): %c%c\n", tr + 'a', tc + 'a');
        makeMove(board,n,computerColour,iToC(tr),iToC(tc));
        printBoard(board,n);
        compMoves++;
      }else if(moveCount!=n*n-4){
        cHasMove=false;
        printf("%c player has no valid move.\n",computerColour);
        //return playerColour;
      }
    }else if(playerColour=='W'){
      if(scoreMoves(board,n,computerColour,&cRow,&cCol)>0){
        int tr,tc;
        findSmartestMove(board, n, computerColour, &tr, &tc);
        printf("Testing AI move (row, col): %c%c\n", tr + 'a', tc + 'a');
        makeMove(board,n,computerColour,iToC(tr),iToC(tc));
        printBoard(board,n);
        compMoves++;
      }else if(moveCount!=n*n-4){
        cHasMove=false;
        printf("%c player has no valid move.\n",computerColour);
        //return playerColour;
      }

      clock_t begin = clock();

      if(scoreBotMoves(board,n,moveCount,playerColour,&cRow,&cCol)>0){
        printf("Bot places %c at %c%c.\n",playerColour,cRow,cCol);
        makeMove(board,n,playerColour,cRow,cCol);
        printBoard(board,n);
        botMoves++;
      }else if(moveCount!=n*n-4){
        pHasMove=false;
        printf("%c player has no valid move.\n",playerColour);
        //return computerColour;
      }

      clock_t end = clock();
      double duration = (double)(end-begin)/CLOCKS_PER_SEC;
      printf("Bot move ran in %lf seconds.\n",duration);

    }
    //printf("%d %d\n",pHasMove,cHasMove);
    if(!pHasMove&&!cHasMove){
      return countWinner(board,n) ;
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
  printf("white pieces: %d\nblack pieces: %d\n",wCount,bCount);
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

int scoreBotMoves(char board[][26],int n,int moveCount,char colour,char* row,char* col){
  int maxscore = 0,tempscore = 0,validmoves=0,maxsize=n*n-4;
  char tempboard[n][26];
  memcpy(&tempboard[0][0],&board[0][0],n*26*sizeof(board[0][0]));
  char brow,bcol;
  if(moveCount<n*n-10){
    validmoves=makeDecision(tempboard,n,1,moveCount,INT_MIN,INT_MAX,colour,&brow,&bcol);
  }else{
    validmoves=makeDecision(tempboard,n,10,moveCount,INT_MIN,INT_MAX,colour,&brow,&bcol);
  }
  *row = brow;
  *col = bcol;
  return validmoves;
}

int countHeuristic(char board[][26],int n,char playerColour){
  int maxsize = n*n-4;

  float coinParity=0.0,coinStability=0.0,cornerValue=0.0,mobilityValue=0.0,cornerCloseness=0.0,winWeighting=1.0;

  int ptiles=0,otiles=0,pMtiles=0,oMtiles=0,pCtiles=0,oCtiles=0,pCCtiles=0,oCCtiles=0;

  char opponentColour = getOppositeColour(playerColour);
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      //calculate number of player/opponent tiles
      if(board[i][j]==playerColour){
        ptiles++;
      }else if(board[i][j]==opponentColour){
        otiles++;
      }
      if((i==0&&j==0)||(i==0&&j==n-1)||(i==n-1&&j==0)||(i==n-1&&j==n-1)){
        if(board[i][j]==playerColour){
          pCtiles++;
        }else if(board[i][j]==opponentColour){
          oCtiles++;
        }
      }
      if(isCornerClose(board,n,i,j)){
        if(board[i][j]==playerColour){
          pCCtiles++;
        }else if(board[i][j]==opponentColour){
          oCCtiles++;
        }
      }
      //calculate tile stability
      for(int x = -1;x <=1;x++){
        for(int y = -1;y <=1;y++){
          int r = i+x,s=j+y;
          if(r>=0&&s>=0&&s<n&&r<n&&board[r][s]=='U'){
            if(board[i][j]==playerColour){
              pMtiles++;
            }else if(board[i][j]==opponentColour){
              oMtiles++;
            }
          }
        }
      }
    }
  }

  if(ptiles+otiles==n*n && ptiles>otiles){
    winWeighting=1000;
  }else if(ptiles<otiles){
    winWeighting=-1000;
  }


  cornerValue=(pCtiles-oCtiles)*25.0;
  cornerCloseness=(pCCtiles-oCCtiles)*-12.5;

  int nPMoves=getNumAvailableMoves(board,n,playerColour);
  int nOMoves=getNumAvailableMoves(board,n,opponentColour);
  if(nPMoves!=nOMoves){
    mobilityValue = (double) (100.0*nPMoves)/(nPMoves+nOMoves)*((nPMoves>nOMoves)?1:-1);
  }
  if(ptiles!=otiles){
    coinParity = (double) (100.0*ptiles)/(ptiles+otiles)*((ptiles>otiles)?1:-1);
  }
  if(pMtiles!=oMtiles){
    coinStability = (double) (100.0*pMtiles)/(pMtiles+oMtiles)*((pMtiles>oMtiles)?1:-1);
  }
  //printBoard(board,n);
  float score = winWeighting+(75*coinParity+500000*cornerValue+1200*cornerCloseness+120*coinStability+120*mobilityValue);
  //printf("%lf %lf %lf %lf %lf score: %d\n\n",coinParity,cornerValue,cornerCloseness,coinStability,mobilityValue,(int)score);

  return (int)score;
}

int makeDecision(char board[][26],int n,int depth,int moveCount,int a,int b,char colour,char* row,char* col){
  int maxsize = n*n-4;
  char* rowArr = (char*)malloc(maxsize*sizeof(char));
  char* colArr = (char*)malloc(maxsize*sizeof(char));
  int nMoves=getAvailableMoves(board,n,colour,rowArr,colArr);
  int maxval = INT_MIN;
  char cRow,cCol;
  if(nMoves==0){
    return 0;
  }else{
    cRow = rowArr[0],
    cCol = colArr[0];
    for(int i = 0;i < nMoves;i++){
      clock_t lookaheadStart = clock();
      makeMove(board,n,colour,rowArr[i],colArr[i]);
      int val = minimax(board,n,depth-1,moveCount+1,lookaheadStart,nMoves,a,b,(colour),getOppositeColour(colour));

      if(val>maxval){
        maxval = val;
        cRow = rowArr[i];
        cCol = colArr[i];
      }
    }
  }
  *row = cRow;
  *col = cCol;
  //printf("score: %d\n",maxval);
  return nMoves;
}

int minimax(char board[][26],int n,int depth,int moveCount,clock_t processingTime,int numMoves,int a,int b,char playerColour,char colour){
  int maxsize = n*n-4;
  if(depth==0||moveCount == maxsize){
    return countHeuristic(board,n,playerColour);
  }
  char* rowArr = (char*)malloc(maxsize*sizeof(char));
  char* colArr = (char*)malloc(maxsize*sizeof(char));
  int nMoves=getAvailableMoves(board,n,colour,rowArr,colArr);
  int value = INT_MIN;
  if(nMoves==0){
    return minimax(board,n,depth-1,moveCount+1,processingTime,numMoves,-b,-a,playerColour,getOppositeColour(colour));
  }else{
    int maxval = (colour==playerColour)?INT_MIN:INT_MAX;
    for(int i = 0;i < nMoves;i++){
      char tempboard[n][26];
      memcpy(&tempboard[0][0],&board[0][0],n*26*sizeof(board[0][0]));
      makeMove(tempboard,n,colour,rowArr[i],colArr[i]);
      value=minimax(tempboard,n,depth-1,moveCount+1,processingTime,numMoves,-b,-a,playerColour,getOppositeColour(colour));
      //printf("%c%c move on %c's turn (turn number = %d) has score %d\n",rowArr[i],colArr[i],colour,moveCount,value);
      if(colour==playerColour){
        if(value>maxval){
          maxval = value;
        }
      }else{
        if(value<maxval){
          maxval = value;
        }
      }
      a=max(a,value);
      if(a>=b){
        break;
      }
      if(calculateElapsedTime(processingTime)>925/numMoves){
        return maxval;
      }
    }
    return maxval;
  }
  return -1;
}

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

int nextGuess(int alpha,int beta,int numMoves){
  return alpha+(beta-alpha)*(numMoves-1)/numMoves;
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

int getNumAvailableMoves(char board[][26],int n,char colour){
  int count = 0;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(board[i][j]=='U'&&checkLegalInAllDirections(board,n,i,j,colour)){
        count++;
      }
    }
  }
  return count;
}

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

int max(int a,int b){
  return (a>=b)?a:b;
}

int min(int a,int b){
  return (a<=b)?a:b;
}

int getDistance(int ax,int ay,int bx,int by){
  return (ax-bx)*((ax>bx)?1:-1)+(ay-by)*((ay>by)?1:-1);
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

int calculateElapsedTime(clock_t start){
  clock_t current = clock();
  double duration = (double)(current-start)/CLOCKS_PER_SEC;
  duration*=1000;
  return (int) duration;
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

int main(void){

  int n=0;
  char winner;
  char result = ' ',playerColour,computerColour;

  getSize(&n);
  char board[n][26];

  getPlayerColours(&computerColour,&playerColour);

  createBoard(board,n);
  printBoard(board,n);

  //winner = mainGameLoop(board,n,playerColour,computerColour);
  winner = testGameLoop(board,n,playerColour,computerColour);
  if(winner!='D'){
    printf("%c player wins.\n",winner);
  }else{
    printf("Draw!");
  }
  return 0;
}
