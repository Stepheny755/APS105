#include <stdio.h>

int main(void){

  double dailyRate,totalCharge;
  const double HST = 0.13;
  int rentalPeriod,freeDays;

  printf("Enter the daily rate: ");
  scanf("%lf",&dailyRate);
  printf("Enter the rental period (in days): ");
  scanf("%d",&rentalPeriod);

  freeDays = rentalPeriod/4;
  totalCharge = (rentalPeriod-freeDays)*(HST+1)*dailyRate;

  printf("Your total free day(s) in this rental is: %d\n",freeDays);
  printf("Your total charge including taxes is: %.2lf\n",totalCharge);

  return 0;

}
