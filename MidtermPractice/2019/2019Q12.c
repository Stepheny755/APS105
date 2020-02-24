#include <stdio.h>

void calculatePascalRowSeven(int pArray[]);

int main(void){
  // row #n has n + 1 elements
  int pascalRow[7 + 1] = {1, 0, 0, 0, 0, 0, 0, 0};

  calculatePascalRowSeven(pascalRow);
  printf("Row 7 is:\n");
  for (int i = 0; i <= 7; i++) {
    printf("%d ", pascalRow[i]);
  }
  printf("\n");

  return 0;
}

void calculatePascalRowSeven(int pArray[]){
  pArray[0]=1;
  for(int i = 0;i<=7;i++){
    for(int j = i;j >= 1;j--){
      pArray[j]=pArray[j-1]+pArray[j];
    }
  }
}
