#include <stdio.h>

double owedAmount(double interest,double owedFromPreviousMonth,double purchases,double monthlyPayment,double* totalInterest);

int main(void){

  double amountOwed,monthlyPayment,monthlyPurchase,interestRate;
  double totalPurchasedValue=0,totalInterestCharges=0;
  int months;

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

  interestRate=interestRate/100/12;

  totalPurchasedValue+=amountOwed;
  for(int i = 0;i<months;i++){
    amountOwed = owedAmount(interestRate,amountOwed,monthlyPurchase,monthlyPayment,&totalInterestCharges);
    totalPurchasedValue+=monthlyPurchase;
    printf("amountOwed: %.2lf\n",amountOwed);
    printf("totalPurchasedValue: %.2lf",totalPurchasedValue);
  }

  printf("Total purchased value: %.2lf\n",totalPurchasedValue);
  printf("Total interest charges: %.2lf\n",totalInterestCharges);

  return 0;
}

double owedAmount(double interest, double owedFromPreviousMonth,double purchases, double monthlyPayment,double* totalInterest){
  double initialAmount = (owedFromPreviousMonth+purchases);//Amount owed originally
  double additionalAmount = (initialAmount)*interest;//Amount owed from interest
  double totalOwedAmount = initialAmount+additionalAmount-monthlyPayment;
  if(owedFromPreviousMonth==0){
    if(monthlyPayment>=initialAmount){
      return 0;
    }else{
      *totalInterest+=additionalAmount;
      return totalOwedAmount;
    }
  }
  *totalInterest+=additionalAmount;
  //printf("initialAmount=%.2lf ",initialAmount);
  //printf("additionalAmount=%.2lf\n",additionalAmount);
  if(totalOwedAmount<0){
    return 0;
  }else{
    return totalOwedAmount;
  }
}
