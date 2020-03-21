#include <stdio.h>

struct Date{
  int year;
  int month;
  int day;
}today; //creates a date struct

typedef double Real;
typedef struct Date DateDT;

struct Student{
  int id;
  char* firstName;
  char* lastName;
  double GPA;
  struct Date birthday;
};

int main(void){

  //always include struct keyword in creating data type of type struct name
  //typedef allows for shortening of struct name
  //typedef renames data type into custom name

  Real a; // type: double

  struct Date bd1;
  bd1.day = 3;
  bd1.month = 11;
  bd1.year = 2000;

  return 0;
}
