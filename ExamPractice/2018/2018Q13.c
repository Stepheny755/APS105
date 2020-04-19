#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* link;
}Node;

void printDuplicates(Node* head){
  Node* current = head;
  while(current->link!=NULL&&current!=NULL){
    Node* begin = current;
    while(begin->link!=NULL){
      begin=begin->link;
      if(begin->data==current->data){
        printf("%d\n",current->data);
      }
    }
    current=current->link;
  }
}

Node* createNode(int value){
  Node* temp = malloc(sizeof(Node));
  temp->data = value;
  temp->link = NULL;
  return temp;
}

int main(void){
  Node* head = createNode(6);
  head->link=createNode(3);
  head->link->link=createNode(3);
  head->link->link->link=createNode(6);
  head->link->link->link->link=createNode(7);
  head->link->link->link->link->link=createNode(4);
  printDuplicates(head);

  return 0;
}
