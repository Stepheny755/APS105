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

void initLinkedList(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

void initNamedList(char* listName,NamedList *list){
  LinkedList* value = (LinkedList*)malloc(sizeof(LinkedList));
  initLinkedList(value);
  list->name=listName;
  list->list=value;
}

void parseList(char** rawRecipes){
  int i = 0,r = 0;
  char* currentElement = rawRecipes[0];

  LinkedList* Ingredients = (LinkedList*)malloc(sizeof(LinkedList));
  LinkedList* Recipes = (LinkedList*)malloc(sizeof(LinkedList));
  initLinkedList(Ingredients);
  initLinkedList(Recipes);

  NamedList* currentRecipe;

  while(currentElement!=""){
    currentElement = rawRecipes[i];
    char* currentIngredient = shiftStr(currentElement);

    if(currentElement[0]=='0'){
      r=1;
      currentRecipe = (NamedList*)malloc(sizeof(NamedList));
      initNamedList(currentIngredient,currentRecipe);
      printf("%s\n",shiftStr(currentElement));
    }
    i++;
    if(r>0){
      Node* ingredient = createNode(currentIngredient);

    }
  }
}

int main(void){

  parseList(rawRecipes);



  return 0;
}
