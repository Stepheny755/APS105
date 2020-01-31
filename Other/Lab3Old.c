#include <stdio.h>

int main(void){

  char resistor1Band1,resistor1Band2,resistor1Multiplier,resistor1Tolerance;
  char resistor2Band1,resistor2Band2,resistor2Multiplier,resistor2Tolerance;
  double resistor1Value=0.0,resistor2Value=0.0,resistor1ToleranceValue,resistor2ToleranceValue;

  printf("Please enter the 1st band of resistor 1:\n");
  scanf(" %c",&resistor1Band1);
  printf("Please enter the 2nd band of resistor 1:\n");
  scanf(" %c",&resistor1Band2);
  printf("Please enter the multiplier band of resistor 1:\n");
  scanf(" %c",&resistor1Multiplier);
  printf("Please enter the tolerance band of resistor 1:\n");
  scanf(" %c",&resistor1Tolerance);

  printf("Please enter the 1st band of resistor 2:\n");
  scanf(" %c",&resistor2Band1);
  printf("Please enter the 2nd band of resistor 2:\n");
  scanf(" %c",&resistor2Band2);
  printf("Please enter the multiplier band of resistor 2:\n");
  scanf(" %c",&resistor2Multiplier);
  printf("Please enter the tolerance band of resistor 2:\n");
  scanf(" %c",&resistor2Tolerance);

  if(resistor1Band1=='K'||resistor1Band1=='k'){
    resistor1Value+=0*10;
  }else if(resistor1Band1=='B'||resistor1Band1=='b'){
    resistor1Value+=1*10;
  }else if(resistor1Band1=='R'||resistor1Band1=='r'){
    resistor1Value+=2*10;
  }else if(resistor1Band1=='O'||resistor1Band1=='o'){
    resistor1Value+=3*10;
  }else if(resistor1Band1=='E'||resistor1Band1=='e'){
    resistor1Value+=4*10;
  }else if(resistor1Band1=='G'||resistor1Band1=='g'){
    resistor1Value+=5*10;
  }else if(resistor1Band1=='U'||resistor1Band1=='u'){
    resistor1Value+=6*10;
  }else if(resistor1Band1=='V'||resistor1Band1=='v'){
    resistor1Value+=7*10;
  }else if(resistor1Band1=='Y'||resistor1Band1=='y'){
    resistor1Value+=8*10;
  }else if(resistor1Band1=='W'||resistor1Band1=='w'){
    resistor1Value+=9*10;
  }else{

  }

  if(resistor1Band2=='K'||resistor1Band2=='k'){
    resistor1Value+=0;
  }else if(resistor1Band2=='B'||resistor1Band2=='b'){
    resistor1Value+=1;
  }else if(resistor1Band2=='R'||resistor1Band2=='r'){
    resistor1Value+=2;
  }else if(resistor1Band2=='O'||resistor1Band2=='o'){
    resistor1Value+=3;
  }else if(resistor1Band2=='E'||resistor1Band2=='e'){
    resistor1Value+=4;
  }else if(resistor1Band2=='G'||resistor1Band2=='g'){
    resistor1Value+=5;
  }else if(resistor1Band2=='U'||resistor1Band2=='u'){
    resistor1Value+=6;
  }else if(resistor1Band2=='V'||resistor1Band2=='v'){
    resistor1Value+=7;
  }else if(resistor1Band2=='Y'||resistor1Band2=='y'){
    resistor1Value+=8;
  }else if(resistor1Band2=='W'||resistor1Band2=='w'){
    resistor1Value+=9;
  }else{

  }

  if(resistor1Multiplier=='K'||resistor1Multiplier=='k'){
    resistor1Value*=1;
  }else if(resistor1Multiplier=='B'||resistor1Multiplier=='b'){
    resistor1Value*=10;
  }else if(resistor1Multiplier=='R'||resistor1Multiplier=='r'){
    resistor1Value*=100;
  }else if(resistor1Multiplier=='O'||resistor1Multiplier=='o'){
    resistor1Value*=1000;
  }else if(resistor1Multiplier=='E'||resistor1Multiplier=='e'){
    resistor1Value*=10000;
  }else if(resistor1Multiplier=='G'||resistor1Multiplier=='g'){
    resistor1Value*=100000;
  }else if(resistor1Multiplier=='U'||resistor1Multiplier=='u'){
    resistor1Value*=1000000;
  }else if(resistor1Multiplier=='V'||resistor1Multiplier=='v'){
    resistor1Value*=10000000;
  }else if(resistor1Multiplier=='L'||resistor1Multiplier=='l'){
    resistor1Value*=0.1;
  }else if(resistor1Multiplier=='S'||resistor1Multiplier=='s'){
    resistor1Value*=0.01;
  }else{

  }

  if(resistor1Tolerance=='B'||resistor1Tolerance=='b'){
    resistor1ToleranceValue=1.0;
  }else if(resistor1Tolerance=='R'||resistor1Tolerance=='r'){
    resistor1ToleranceValue=2.0;
  }else if(resistor1Tolerance=='G'||resistor1Tolerance=='g'){
    resistor1ToleranceValue=0.5;
  }else if(resistor1Tolerance=='U'||resistor1Tolerance=='u'){
    resistor1ToleranceValue=0.25;
  }else if(resistor1Tolerance=='V'||resistor1Tolerance=='v'){
    resistor1ToleranceValue=0.1;
  }else if(resistor1Tolerance=='Y'||resistor1Tolerance=='y'){
    resistor1ToleranceValue=0.05;
  }else if(resistor1Tolerance=='L'||resistor1Tolerance=='l'){
    resistor1ToleranceValue=5.0;
  }else if(resistor1Tolerance=='S'||resistor1Tolerance=='s'){
    resistor1ToleranceValue=10.0;
  }else{

  }

  if(resistor2Band1=='K'||resistor2Band1=='k'){
    resistor2Value+=0*10;
  }else if(resistor2Band1=='B'||resistor2Band1=='b'){
    resistor2Value+=1*10;
  }else if(resistor2Band1=='R'||resistor2Band1=='r'){
    resistor2Value+=2*10;
  }else if(resistor2Band1=='O'||resistor2Band1=='o'){
    resistor2Value+=3*10;
  }else if(resistor2Band1=='E'||resistor2Band1=='e'){
    resistor2Value+=4*10;
  }else if(resistor2Band1=='G'||resistor2Band1=='g'){
    resistor2Value+=5*10;
  }else if(resistor2Band1=='U'||resistor2Band1=='u'){
    resistor2Value+=6*10;
  }else if(resistor2Band1=='V'||resistor2Band1=='v'){
    resistor2Value+=7*10;
  }else if(resistor2Band1=='Y'||resistor2Band1=='y'){
    resistor2Value+=8*10;
  }else if(resistor2Band1=='W'||resistor2Band1=='w'){
    resistor2Value+=9*10;
  }else{

  }

  if(resistor2Band2=='K'||resistor2Band2=='k'){
    resistor2Value+=0;
  }else if(resistor2Band2=='B'||resistor2Band2=='b'){
    resistor2Value+=1;
  }else if(resistor2Band2=='R'||resistor2Band2=='r'){
    resistor2Value+=2;
  }else if(resistor2Band2=='O'||resistor2Band2=='o'){
    resistor2Value+=3;
  }else if(resistor2Band2=='E'||resistor2Band2=='e'){
    resistor2Value+=4;
  }else if(resistor2Band2=='G'||resistor2Band2=='g'){
    resistor2Value+=5;
  }else if(resistor2Band2=='U'||resistor2Band2=='u'){
    resistor2Value+=6;
  }else if(resistor2Band2=='V'||resistor2Band2=='v'){
    resistor2Value+=7;
  }else if(resistor2Band2=='Y'||resistor2Band2=='y'){
    resistor2Value+=8;
  }else if(resistor2Band2=='W'||resistor2Band2=='w'){
    resistor2Value+=9;
  }else{

  }

  if(resistor2Multiplier=='K'||resistor2Multiplier=='k'){
    resistor2Value*=1;
  }else if(resistor2Multiplier=='B'||resistor2Multiplier=='b'){
    resistor2Value*=10;
  }else if(resistor2Multiplier=='R'||resistor2Multiplier=='r'){
    resistor2Value*=100;
  }else if(resistor2Multiplier=='O'||resistor2Multiplier=='o'){
    resistor2Value*=1000;
  }else if(resistor2Multiplier=='E'||resistor2Multiplier=='e'){
    resistor2Value*=10000;
  }else if(resistor2Multiplier=='G'||resistor2Multiplier=='g'){
    resistor2Value*=100000;
  }else if(resistor2Multiplier=='U'||resistor2Multiplier=='u'){
    resistor2Value*=1000000;
  }else if(resistor2Multiplier=='V'||resistor2Multiplier=='v'){
    resistor2Value*=10000000;
  }else if(resistor2Multiplier=='L'||resistor2Multiplier=='l'){
    resistor2Value*=0.1;
  }else if(resistor2Multiplier=='S'||resistor2Multiplier=='s'){
    resistor2Value*=0.01;
  }else{

  }

  if(resistor2Tolerance=='B'||resistor2Tolerance=='b'){
    resistor2ToleranceValue=1.0;
  }else if(resistor2Tolerance=='R'||resistor2Tolerance=='r'){
    resistor2ToleranceValue=2.0;
  }else if(resistor2Tolerance=='G'||resistor2Tolerance=='g'){
    resistor2ToleranceValue=0.5;
  }else if(resistor2Tolerance=='U'||resistor2Tolerance=='u'){
    resistor2ToleranceValue=0.25;
  }else if(resistor2Tolerance=='V'||resistor2Tolerance=='v'){
    resistor2ToleranceValue=0.1;
  }else if(resistor2Tolerance=='Y'||resistor2Tolerance=='y'){
    resistor2ToleranceValue=0.05;
  }else if(resistor2Tolerance=='L'||resistor2Tolerance=='l'){
    resistor2ToleranceValue=5.0;
  }else if(resistor2Tolerance=='S'||resistor2Tolerance=='s'){
    resistor2ToleranceValue=10.0;
  }else{

  }

  char tempValue;
  double resistor1ValueTemp=resistor1Value,resistor2ValueTemp=resistor2Value;

  printf("\nColour Bands for resistor 1: \n");

  tempValue = resistor1Band1;
  if(tempValue=='K'||tempValue=='k'){
    printf("Black ");
  }else if(tempValue=='B'||tempValue=='b'){
    printf("Brown ");
  }else if(tempValue=='R'||tempValue=='r'){
    printf("Red ");
  }else if(tempValue=='O'||tempValue=='o'){
    printf("Orange ");
  }else if(tempValue=='E'||tempValue=='e'){
    printf("Yellow ");
  }else if(tempValue=='G'||tempValue=='g'){
    printf("Green ");
  }else if(tempValue=='U'||tempValue=='u'){
    printf("Blue ");
  }else if(tempValue=='V'||tempValue=='v'){
    printf("Violet ");
  }else if(tempValue=='Y'||tempValue=='y'){
    printf("Grey ");
  }else if(tempValue=='W'||tempValue=='w'){
    printf("White ");
  }else{
    printf("\nInvalid colour for the 1st band of resistor 1. Exiting the program...\n");
    return 0;
  }

  tempValue = resistor1Band2;
  if(tempValue=='K'||tempValue=='k'){
    printf("Black ");
  }else if(tempValue=='B'||tempValue=='b'){
    printf("Brown ");
  }else if(tempValue=='R'||tempValue=='r'){
    printf("Red ");
  }else if(tempValue=='O'||tempValue=='o'){
    printf("Orange ");
  }else if(tempValue=='E'||tempValue=='e'){
    printf("Yellow ");
  }else if(tempValue=='G'||tempValue=='g'){
    printf("Green ");
  }else if(tempValue=='U'||tempValue=='u'){
    printf("Blue ");
  }else if(tempValue=='V'||tempValue=='v'){
    printf("Violet ");
  }else if(tempValue=='Y'||tempValue=='y'){
    printf("Grey ");
  }else if(tempValue=='W'||tempValue=='w'){
    printf("White ");
  }else{
    printf("\nInvalid colour for the 2nd band of resistor 1. Exiting the program...\n");
    return 0;
  }

  tempValue = resistor1Multiplier;
  if(tempValue=='K'||tempValue=='k'){
    printf("Black ");
  }else if(tempValue=='B'||tempValue=='b'){
    printf("Brown ");
  }else if(tempValue=='R'||tempValue=='r'){
    printf("Red ");
  }else if(tempValue=='O'||tempValue=='o'){
    printf("Orange ");
  }else if(tempValue=='E'||tempValue=='e'){
    printf("Yellow ");
  }else if(tempValue=='G'||tempValue=='g'){
    printf("Green ");
  }else if(tempValue=='U'||tempValue=='u'){
    printf("Blue ");
  }else if(tempValue=='V'||tempValue=='v'){
    printf("Violet ");
  }else if(tempValue=='L'||tempValue=='l'){
    printf("Gold ");
  }else if(tempValue=='S'||tempValue=='s'){
    printf("Silver ");
  }else{
    printf("\nInvalid colour for the multiplier band of resistor 1. Exiting the program...\n");
    return 0;
  }

  tempValue = resistor1Tolerance;
  if(tempValue=='K'||tempValue=='k'){
    printf("Black ");
  }else if(tempValue=='B'||tempValue=='b'){
    printf("Brown ");
  }else if(tempValue=='R'||tempValue=='r'){
    printf("Red ");
  }else if(tempValue=='G'||tempValue=='g'){
    printf("Green ");
  }else if(tempValue=='U'||tempValue=='u'){
    printf("Blue ");
  }else if(tempValue=='V'||tempValue=='v'){
    printf("Violet ");
  }else if(tempValue=='Y'||tempValue=='y'){
    printf("Grey ");
  }else if(tempValue=='L'||tempValue=='l'){
    printf("Gold ");
  }else if(tempValue=='S'||tempValue=='s'){
    printf("Silver ");
  }else{
    printf("\nInvalid colour for the tolerance band of resistor 1. Exiting the program...\n");
    return 0;
  }

  printf("\nColour Bands for resistor 2: \n");

  tempValue = resistor2Band1;
  if(tempValue=='K'||tempValue=='k'){
    printf("Black ");
  }else if(tempValue=='B'||tempValue=='b'){
    printf("Brown ");
  }else if(tempValue=='R'||tempValue=='r'){
    printf("Red ");
  }else if(tempValue=='O'||tempValue=='o'){
    printf("Orange ");
  }else if(tempValue=='E'||tempValue=='e'){
    printf("Yellow ");
  }else if(tempValue=='G'||tempValue=='g'){
    printf("Green ");
  }else if(tempValue=='U'||tempValue=='u'){
    printf("Blue ");
  }else if(tempValue=='V'||tempValue=='v'){
    printf("Violet ");
  }else if(tempValue=='Y'||tempValue=='y'){
    printf("Grey ");
  }else if(tempValue=='W'||tempValue=='w'){
    printf("White ");
  }else{
    printf("\nInvalid colour for the 1st band of resistor 2. Exiting the program...\n");
    return 0;
  }

  tempValue = resistor2Band2;
  if(tempValue=='K'||tempValue=='k'){
    printf("Black ");
  }else if(tempValue=='B'||tempValue=='b'){
    printf("Brown ");
  }else if(tempValue=='R'||tempValue=='r'){
    printf("Red ");
  }else if(tempValue=='O'||tempValue=='o'){
    printf("Orange ");
  }else if(tempValue=='E'||tempValue=='e'){
    printf("Yellow ");
  }else if(tempValue=='G'||tempValue=='g'){
    printf("Green ");
  }else if(tempValue=='U'||tempValue=='u'){
    printf("Blue ");
  }else if(tempValue=='V'||tempValue=='v'){
    printf("Violet ");
  }else if(tempValue=='Y'||tempValue=='y'){
    printf("Grey ");
  }else if(tempValue=='W'||tempValue=='w'){
    printf("White ");
  }else{
    printf("\nInvalid colour for the 2nd band of resistor 2. Exiting the program...\n");
    return 0;
  }

  tempValue = resistor2Multiplier;
  if(tempValue=='K'||tempValue=='k'){
    printf("Black ");
  }else if(tempValue=='B'||tempValue=='b'){
    printf("Brown ");
  }else if(tempValue=='R'||tempValue=='r'){
    printf("Red ");
  }else if(tempValue=='O'||tempValue=='o'){
    printf("Orange ");
  }else if(tempValue=='E'||tempValue=='e'){
    printf("Yellow ");
  }else if(tempValue=='G'||tempValue=='g'){
    printf("Green ");
  }else if(tempValue=='U'||tempValue=='u'){
    printf("Blue ");
  }else if(tempValue=='V'||tempValue=='v'){
    printf("Violet ");
  }else if(tempValue=='L'||tempValue=='l'){
    printf("Gold ");
  }else if(tempValue=='S'||tempValue=='s'){
    printf("Silver ");
  }else{
    printf("\nInvalid colour for the multiplier band of resistor 2. Exiting the program...\n");
    return 0;
  }

  tempValue = resistor2Tolerance;
  if(tempValue=='K'||tempValue=='k'){
    printf("Black ");
  }else if(tempValue=='B'||tempValue=='b'){
    printf("Brown ");
  }else if(tempValue=='R'||tempValue=='r'){
    printf("Red ");
  }else if(tempValue=='G'||tempValue=='g'){
    printf("Green ");
  }else if(tempValue=='U'||tempValue=='u'){
    printf("Blue ");
  }else if(tempValue=='V'||tempValue=='v'){
    printf("Violet ");
  }else if(tempValue=='Y'||tempValue=='y'){
    printf("Grey ");
  }else if(tempValue=='L'||tempValue=='l'){
    printf("Gold ");
  }else if(tempValue=='S'||tempValue=='s'){
    printf("Silver ");
  }else{
    printf("\nInvalid colour for the tolerance band of resistor 2. Exiting the program...\n");
    return 0;
  }

  char *resistance1Units,*resistance2Units,*eqSeriesUnits,*eqParallelUnits;
  double eqSeriesResistance,eqParallelResistance;
  eqSeriesResistance = resistor1Value+resistor2Value;
  eqParallelResistance = 1/(1/resistor1Value+1/resistor2Value);

  if(resistor1Value>=1e6){
    resistor1ValueTemp/=1e6;
    resistance1Units = "MOhms";
  }else if(resistor1Value>=1e3){
    resistor1ValueTemp/=1e3;
    resistance1Units = "KOhms";
  }else{
    resistance1Units = "Ohms";
  }

  if(resistor2Value>=1e6){
    resistor2ValueTemp/=1e6;
    resistance2Units = "MOhms";
  }else if(resistor2Value>=1e3){
    resistor2ValueTemp/=1e3;
    resistance2Units = "KOhms";
  }else{
    resistance2Units = "Ohms";
  }

  if(eqSeriesResistance>=1e6){
    eqSeriesResistance/=1e6;
    eqSeriesUnits = "MOhms";
  }else if(eqSeriesResistance>=1e3){
    eqSeriesResistance/=1e3;
    eqSeriesUnits = "KOhms";
  }else{
    eqSeriesUnits = "Ohms";
  }

  if(eqParallelResistance>=1e6){
    eqParallelResistance/=1e6;
    eqParallelUnits = "MOhms";
  }else if(eqParallelResistance>=1e3){
    eqParallelResistance/=1e3;
    eqParallelUnits = "KOhms";
  }else{
    eqParallelUnits = "Ohms";
  }

  printf("\nValue in ohms of resistor 1: \n");
  printf("%.2lf %s +/- %.2lf%%\n",resistor1ValueTemp,resistance1Units,resistor1ToleranceValue);
  printf("Value in ohms of resistor 2: \n");
  printf("%.2lf %s +/- %.2lf%%\n",resistor2ValueTemp,resistance2Units,resistor2ToleranceValue);

  printf("\nThe Equivalent in series is %.2lf %s",eqSeriesResistance,eqSeriesUnits);
  printf("\nThe Equivalent in parallel is %.2lf %s\n",eqParallelResistance,eqParallelUnits);


  return 0;
}