#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rawRecipes.h"

typedef struct node{
  char* name;
  struct node* next;
}Node;

typedef struct linkedlist{
  Node *head;
  Node *tail;
}LinkedList;

char* shiftStr(char* str){
  char* shifted = (char*)malloc(sizeof(char)*60);
  strcpy(shifted,str+1);
  return shifted;
}

Node* createNode(char* data){
  Node* new = (Node*)malloc(sizeof(Node));
  if(new!=NULL){
    new->value=data;
    new->rownext=NULL;
  }
  return new;
}

void initList(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

void parseList(char** rawRecipes){
  int i = 0;
  while(s!=""){
    printf("%s\n",s);
    char* s = rawRecipes[i];
    if()
    //printf("%s\n",shiftStr(s));
    i++;
  }
}

int main(void){

  LinkedList* Ingredients = (LinkedList*)malloc(sizeof(LinkedList));
  LinkedList* Recipes = (LinkedList*)malloc(sizeof(LinkedList));
  initList(Ingredients);
  initList(Recipes);
  parseList(rawRecipes);



  return 0;
}
