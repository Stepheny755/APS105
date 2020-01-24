#include <stdio.h>

int main(void){

  //variable declarations
  double dailyRate,totalCharge;
  const double HST = 0.13;
  int rentalPeriod,freeDays;

  //get daily rate and rental period from console input
  printf("Enter the daily rate: ");
  scanf("%lf",&dailyRate);
  printf("Enter the rental period (in days): ");
  scanf("%d",&rentalPeriod);

  //calculate number of free days in total rental period
  freeDays = rentalPeriod/4;
  //calculate total charge of rental period
  totalCharge = (rentalPeriod-freeDays)*(HST+1)*dailyRate;

  //display number of free days and the total charge of rental period
  printf("Your total free day(s) in this rental is: %d\n",freeDays);
  printf("The total charge including taxes is: %.2lf\n",totalCharge);

  return 0;

}
