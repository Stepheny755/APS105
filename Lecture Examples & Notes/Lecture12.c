#include <stdio.h>

int main(void){
  
  int digit,n,lastdigit,count=0;

  do{
    printf("Please give a digit from 0 to 9: ");
    scanf("%d",&digit);
  }while(digit<0||digit>9);

  printf("Please enter an integer: ");
  scanf("%d",&n);

  do{
    lastdigit = n%10;
    if(lastdigit==digit){
      count++;
    }
    n/=10;
  }while(n>0);
  printf("The number of occurances of %d is %d",digit,count);
}
