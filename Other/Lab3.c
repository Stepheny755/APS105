#include <stdio.h>

int main(void){

  char resistor1Band1,resistor1Band2,resistor1Multiplier,resistor1Tolerance;
  char resistor2Band1,resistor2Band2,resistor2Multiplier,resistor2Tolerance;
  double resistor1Value=0.0,resistor2Value=0.0,resistor1Tolerance,resistor2Tolerance;

  printf("Please enter the 1st band of resistor 1:\n");
  scanf("%c",&resistor1Band1);
  printf("Please enter the 2nd band of resistor 1:\n");
  scanf("%c",&resistor1Band2);
  printf("Please enter the multiplier band of resistor 1:\n");
  scanf("%c",&resistor1Multiplier);
  printf("Please enter the tolerance band of resistor 1:\n");
  scanf("%c",&resistor1Tolerance);

  printf("Please enter the 1st band of resistor 2:\n");
  scanf("%c",&resistor2Band1);
  printf("Please enter the 2nd band of resistor 2:\n");
  scanf("%c",&resistor2Band2);
  printf("Please enter the multiplier band of resistor 2:\n");
  scanf("%c",&resistor2Multiplier);
  printf("Please enter the tolerance band of resistor 2:\n");
  scanf("%c",&resistor2Tolerance);

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
    resistor1Tolerance=1;
  }else if(resistor1Tolerance=='R'||resistor1Tolerance=='r'){
    resistor1Tolerance=2;
  }else if(resistor1Tolerance=='G'||resistor1Tolerance=='g'){
    resistor1Tolerance=0.5;
  }else if(resistor1Tolerance=='U'||resistor1Tolerance=='u'){
    resistor1Tolerance=0.25;
  }else if(resistor1Tolerance=='V'||resistor1Tolerance=='v'){
    resistor1Tolerance=0.1;
  }else if(resistor1Tolerance=='Y'||resistor1Tolerance=='y'){
    resistor1Tolerance=0.05;
  }else if(resistor1Tolerance=='L'||resistor1Tolerance=='l'){
    resistor1Tolerance=5;
  }else if(resistor1Tolerance=='S'||resistor1Tolerance=='s'){
    resistor1Tolerance=10;
  }else{

  }

  printf("Colour Bands for resistor 1: ")
  printf("Colour Bands for resistor 2: ")
  printf("Value in ohms of resistor 1: ")
  printf("%lf",resistor1Value);
  printf("Value in ohms of resistor 2: ")


  return 0;
}
