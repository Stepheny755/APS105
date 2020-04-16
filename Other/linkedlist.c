#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
  int value;
  struct node* next;
}Node;

typedef struct linkedlist{
  Node* head;
}LinkedList;

Node* createNode(int value){
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->next = NULL;
  if(temp==NULL){
    printf("Error: Could not allocate memory for node");
  }
  return temp;
}

LinkedList* init(int headvalue){
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
  list->head = createNode(headvalue);
  if(list==NULL){
    printf("Error: Could not allocate memory for node");
  }
  return list;
}

bool isEmpty(LinkedList* list){
  return (list->head==NULL);
}

void insertFront(LinkedList* list,int value){
  Node* temp = createNode(value);
  temp->next = list->head;
  list->head = temp;
}

void insertTail(LinkedList* list,int value){
  if(isEmpty(list)){
    list->head=createNode(value);
    return;
  }
  Node* temp = list->head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next = createNode(value);
}

void deleteFront(LinkedList* list){
  Node* temp = list->head;
  list->head = list->head->next;
  free(temp);
}

bool deleteTail(LinkedList* list){
  if(isEmpty(list)){
    return false;
  }else if(list->head->next==NULL){
    deleteFront(list);
    return true;
  }
  Node* temp = list->head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  return true;
}

bool deleteFirstMatch(LinkedList* list,int value){
  if(isEmpty(list)){
    return false;
  }else if(list->head->value==value){
    Node* temp = list->head->next;
    free(list->head);
    list->head = temp;
    return true;
  }
  Node* temp = list->head;
  while(temp->next!=NULL){
    if(temp->next->value==value){
      Node* found = temp->next;
      temp->next=found->next;
      free(found);
      return true;
    }
    temp=temp->next;
  }
  //printf("Error: Cannot find node with value %d in list",value);
  return false;
}

bool deleteAllMatch(LinkedList* list,int value){
  if(isEmpty(list)){
    return false;
  }else{
    while(deleteFirstMatch(list,value)){

    }
  }
}

void deleteList(LinkedList* list){
  while(list->head!=NULL){
    deleteFront(list);
  }
}

void printList(LinkedList* list){
  if(isEmpty(list)){
    printf("Error: List is empty.\n");
    return;
  }
  Node* temp = list->head;
  do{
    printf("%d\n",temp->value);
    temp=temp->next;
  }while(temp!=NULL);
  printf("\n");
}



int main(void){

  LinkedList* list = init(5);
  insertFront(list,4);
  insertFront(list,3);
  insertFront(list,2);
  printList(list);

  insertTail(list,5);
  insertTail(list,5);
  insertTail(list,6);
  insertTail(list,5);
  insertTail(list,5);
  printList(list);

  deleteAllMatch(list,5);
  printList(list);

  return 0;
}
