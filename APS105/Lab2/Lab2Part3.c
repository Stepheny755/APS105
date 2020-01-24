/**
 * APS105 Lab 2
 * Stephen Yang 1005917643
 * 
 * Calculates the price of purchasing a car given monthly payments with interest
 */


#include <stdio.h>
#include <math.h>



int main(void){

  //variable declarations
  int purchasePrice,downPayment,financeTerm;
  double interestRate; //monthly compound periods

  //read variables from console input
  printf("Enter the purchase price P: ");
  scanf("%d",&purchasePrice);
  printf("Enter the amount of down payment D: ");
  scanf("%d",&downPayment);
  printf("Enter the finance term (in months): ");
  scanf("%d",&financeTerm);
  printf("Enter the monthly interest rate (in percent): ");
  scanf("%lf",&interestRate);

  //convert interest rate from percent value to decimal value
  interestRate/=100;
  //calculate monthly payment using interest rate formula
  double monthlyPayment = (purchasePrice-downPayment)*interestRate*pow(1+interestRate,financeTerm)/(pow(1+interestRate,financeTerm)-1);
  //display monthly payment value
  printf("The monthly payment is: %.2lf",monthlyPayment);
}
