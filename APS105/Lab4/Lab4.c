#include <stdio.h>

double owedAmount(double interest,double owedFromPreviousMonth,double purchases,double monthlyPayment,double* totalInterest);

int main(void){

  //variable declarations
  double amountOwed,monthlyPayment,monthlyPurchase,interestRate;
  double totalPurchasedValue=0,totalInterestCharges=0;
  int months;

  //read variables from user input
  printf("Enter amount already owed on card: ");
  scanf("%lf",&amountOwed);
  printf("Enter purchase amount per month: ");
  scanf("%lf",&monthlyPurchase);
  printf("Enter payment amount per month: ");
  scanf("%lf",&monthlyPayment);
  printf("Enter yearly interest rate as percent: ");
  scanf("%lf",&interestRate);
  printf("Enter number of months to consider: ");
  scanf("%d",&months);

  //convert interest rate from annual rate to monthly rate
  interestRate=interestRate/100/12;

  //calculate the total value of purchases (monthly purchases + initial purchase)
  totalPurchasedValue+=amountOwed+monthlyPurchase*months;
  //loop over number of months
  for(int i = 0;i<months;i++){
	//calculate amount owed for each month as a function of previously owed amout
    amountOwed = owedAmount(interestRate,amountOwed,monthlyPurchase,monthlyPayment,&totalInterestCharges);
  }

  //print final values
  printf("Total purchased value: %.2lf\n",totalPurchasedValue);
  printf("Total interest charges: %.2lf\n",totalInterestCharges);

  return 0;
}


//calculates owed amount given interest rate, previous owed amount, monthly purchases and monthly payment
double owedAmount(double interest, double owedFromPreviousMonth,double purchases, double monthlyPayment,double* totalInterest){
  //Amount owed originally
  double initialAmount = (owedFromPreviousMonth+purchases);
  
  //Amount owed from interest
  double additionalAmount = (initialAmount)*interest;
  
  //Total amount owed
  double totalOwedAmount = initialAmount+additionalAmount-monthlyPayment;
  
  if(owedFromPreviousMonth==0){
    if(monthlyPayment>=initialAmount){
	  //if nothing is owned previously AND the full amount owed is payable, then no interest is accumulated
      return 0;
    }else{
	  //if nothing is owned previously AND the full amount owed is not payable, then interest on whole amount is accumulated
	  //add interest accumulated in this month to total interest accumulated
      *totalInterest+=additionalAmount;
      return totalOwedAmount;
    }
  }
  //add interest accumulated in this month to total interest accumulated
  *totalInterest+=additionalAmount;
  
  if(totalOwedAmount<0){
	//if the amount owed is negative (e.g. All the purchases have been paid off), then nothing is owed but interest accumulates
    return 0;
  }else{
	//a positive amount is owed for the next month and interest is accumulated
    return totalOwedAmount;
  }
	
}