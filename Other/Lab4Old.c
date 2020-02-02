#include <stdio.h>

double owedAmount(double interest,double owedFromPreviousMonth,double purchases,double monthlyPayment);

int main(void){

  double amountOwed,monthlyPayment,monthlyPurchase,interestRate;
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

  for(int i = 0;i<months;i++){
    amountOwed = owedAmount(interestRate,amountOwed,monthlyPurchase,monthlyPayment);
    //printf("amountOwed: %.2lf\n",amountOwed);
  }

  printf("%.2lf",amountOwed);

  return 0;
}

double owedAmount(double interest, double owedFromPreviousMonth,double purchases, double monthlyPayment){
  if(owedFromPreviousMonth!=0){
    double totalAmount = owedFromPreviousMonth+purchases;
    double amountOwed = totalAmount + ((totalAmount)*interest);
    printf("amountOwed: %.2lf\n",amountOwed);
    if(monthlyPayment>amountOwed){
      monthlyPayment=amountOwed;
    }
    return amountOwed-monthlyPayment;
  }else{
    if(owedFromPreviousMonth>monthlyPayment){
      double totalAmount = owedFromPreviousMonth+purchases;
      double amountOwed = totalAmount + ((totalAmount)*interest);
      //printf("amountOwed: %.2lf\n",amountOwed);
      if(monthlyPayment>amountOwed){
        monthlyPayment=amountOwed;
      }
      return amountOwed-monthlyPayment;
    }
    return 0;
  }
}

/*
The amount due at the end of the month (where money is owed at the start
of the month) is thus d = u + p + ((u + p) ∗ i) − r where d is the amount due at
the end of the month, u is the previous unpaid amount due, p are the purchases
for that month, r is the amount repaid that month and i is the interest rate per
month. The calculated d become the u for the next month.
*/
