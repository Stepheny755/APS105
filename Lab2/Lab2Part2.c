#include <stdio.h>

int main(void){

  int inputCode;

  //get an encrypted 4 digit combination from console input
  printf("Enter an encrypted 4-digit combination: ");
  scanf("%d",&inputCode);

  //calculate and print the decrypted 4 digit combination
  printf("The real combination is: ");
  printf("%d%d%d%d\n",inputCode%10,9-(inputCode/100%10),9-(inputCode/10%10),inputCode/1000);
  return 0;

}
