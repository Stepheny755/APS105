#include <stdio.h>
#include <math.h>

int main(void){

  int purchasePrice,downPayment,financeTerm;
  double interestRate; //monthly compound periods

  printf("Enter the purchase price P: ");
  scanf("%d",&purchasePrice);
  printf("Enter the amount of down payment D: ");
  scanf("%d",&downPayment);
  printf("Enter the finance term (in months): ");
  scanf("%d",&financeTerm);
  printf("Enter the monthly interest rate (in percent): ");
  scanf("%lf",&interestRate);

  interestRate/=100;
  double monthlyPayment = (purchasePrice-downPayment)*interestRate*pow(1+interestRate,financeTerm)/(pow(1+interestRate,financeTerm)-1);
  printf("The monthly payment is: %.2lf",monthlyPayment);
}
