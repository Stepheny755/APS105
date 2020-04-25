

typedef struct node{
  int value;
  struct node* next;
}Node;

deleteNodeB(Node* head){
  Node* nodeB = head->next;
  head->next=nodeB->next;
  free(nodeB);
}
