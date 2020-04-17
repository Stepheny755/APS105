#include <stdio.h>
#include <stdlib.h>

typedef struct name{
  char* firstname;
  char* lastname;
}Name;

typedef struct employee{
  int SIN;
  int employeeNumber;
  Name *emplName;
}Empl;


int main(){

  Empl employees[1000];
  Empl* temp = (Empl*)malloc(sizeof(Empl));
  temp->employeeNumber = 5;
  temp->SIN=1251;
  Name* tempname = (Name*)malloc(sizeof(Name));
  tempname->firstname = "Alex";
  tempname->lastname="Swriske";
  temp->emplName = tempname;

  employees[1]=*temp;



  char c = *((employees[1]).emplName->lastname); //both work
  c = ((employees[1].emplName)->lastname)[0];


  printf("%c\n",c);
  return 0;
}
