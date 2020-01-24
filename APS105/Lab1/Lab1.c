/**
 * APS105 Lab 1
 * Stephen Yang 1005917643
 * 
 * Takes input of three numbers and outputs the evaluation of some mathematical operations 
 */

#include <stdio.h>

int main(int argc, char **argv){

  //variable declarations for input numbers
  int inputNumber1, inputNumber2, inputNumber3;

  //Read variables from user input
  printf("Enter First Number: ");
  scanf("%d",&inputNumber1);
  printf("Enter Second Number: ");
  scanf("%d",&inputNumber2);
  printf("Enter Third Number: ");
  scanf("%d",&inputNumber3);

  //Display sum of three input numbers
  printf("Sum: %d\n",inputNumber1+inputNumber2+inputNumber3);
  
  //Displays the negative equivalent of inputNumber1
  printf("First Negated: %d\n",inputNumber1*-1);
  
  //Displays inputNumber2 + 1
  printf("After Number 2: %d\n",inputNumber2+1);
  
  //Displays product of inputNumber 2 and inputNumber3
  printf("Product of Number 2 and Number 3: %d\n",inputNumber2*inputNumber3);

  return 0;
}
