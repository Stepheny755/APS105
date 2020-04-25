#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int data;
  struct node *left,right;//CTE, right is of wrong type
}Node;
Node* insert(Node* root,int item){
  if(root == NULL){
    return newNode(item);
  }
  if(item<=(*root).data)
    insert(root->left,item)//CTE, no semicolon here
  return root;
}
int main(void){
  int list[] = {15,3,2};
  Node* root = NULL;
  for(int i = 0;i < 13;i++){//CTE if not in C99
    root = insert(root,list[i]);
  }
  return 0;
}
