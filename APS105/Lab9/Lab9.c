#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rawRecipes.h"

typedef struct node{
  char* value;
  struct node* next;
}Node;

typedef struct linkedlist{
  Node *head;
  Node *tail;
}LinkedList;

typedef struct namedlist{
  char* name;
  LinkedList* list;
}NamedList;

char* shiftStr(char* str){
  char* shifted = (char*)malloc(sizeof(char)*60);
  strcpy(shifted,str+1);
  return shifted;
}

Node* createNode(char* data){
  Node* new = (Node*)malloc(sizeof(Node));
  if(new!=NULL){
    new->value=data;
    new->next=NULL;
  }
  return new;
}

void initNamedList(char* listName,NamedList *list){
  LinkedList* value = (LinkedList*)malloc(sizeof(LinkedList));
  initList(value);
  list->name=listName;
  list->list=value;
}

void initLinkedList(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

void parseList(char** rawRecipes){
  int i = 0;
  char* s = rawRecipes[0];

  LinkedList* Ingredients = (LinkedList*)malloc(sizeof(LinkedList));
  LinkedList* Recipes = (LinkedList*)malloc(sizeof(LinkedList));
  initList(Ingredients);
  initList(Recipes);

  Recipe* currentRecipe = (Recipe*)malloc(sizeof(Recipe));
  initNamedList(currentRecipe);

  while(s!=""){
    s = rawRecipes[i];
    printf("%c\n",s[0]);
    printf("%s\n",s);
    if(s[0]=='0'){
      Recipes->head
      printf("%s\n",s);
    }
    i++;
  }
}

int main(void){

  parseList(rawRecipes);



  return 0;
}
