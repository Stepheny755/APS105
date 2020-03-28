#include <stdio.h>
#include <stdlib.h>

struct Date{
  int day;
  int month;
  int year;
};

struct Student{
  int id;
  char* firstName;
  char* lastName;
  double GPA;
  struct Date birthday;
};


int main(void){

  struct Date myBD; //variable
  myBD.day = 3;
  //notice the dot between "myBD" and "day"
  //dot operator allows accessing of fields of data structure/variable
  myBD.month = 11;
  myBD.year = 2000;

  int a = 5; // a is stored in a certain address (say 1000)
  int* add_a = &a; //add_a stores a certain address (1000) as before

  struct Date* date1; //declare pointer date1
  date1 = (struct Date*)malloc(sizeof(struct Date)); //assign pointer date1
  printf("struct Date size = %d\n",(int)sizeof(struct Date));

  //below two lines are identical in function
  date1->day = 5; //arrow operator to access pointer
  (*date1).day = 5; //or use dot operator on value at address of pointer

  printf("day = %d\n",date1->day);

  //Dynamic Memory Allocation
  struct Date* student1; //only pointer declaration, does not allocate memory for data structure

  student1 = (struct Date*)malloc(sizeof(struct Student));

}
