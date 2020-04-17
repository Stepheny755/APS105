typedef struct node{
  int data;
  sctruct node* link;
}Node;

Node* search(Node* head,int key){
  Node* current = root;
  while((current->data!=key)&&current!=NULL){
    current=current->link;
  }
  return current;
}
