#include <stdio.h>
#include <stdbool.h>

int main(){

  int currentVal = 0,i=0;
  int values[10]={};
  bool isAscending = true;

  do{
    printf("Enter a value (0 to stop):");
    scanf("%d",&currentVal);
    if(currentVal!=0){
        values[i]=currentVal;
        i++;
    }
  }while(currentVal!=0&&i<=10);

  printf("There are a total of %d numbers\n",i);
  printf("The values you entered are: ");

  for(int j = 0;j < i;j++){
    printf("%d ",values[j]);
    if(values[j+1]<values[j]&&j<10&&values[j+1]!=0){

      isAscending=false;
    }
  }

  if(isAscending){
    printf("\nThe values are in ascending order.\n");
  }else{
    printf("\nThe values are not in ascending order.\n");
  }

  return 0;
}
