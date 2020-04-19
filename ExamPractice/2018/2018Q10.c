#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *left,right;//CTE
}Node;

Node* insert(Node* root,int item){
  if(root == NULL){
    return newNode(item);//CTE, newNode not defined
  }
  if(item<=(*root).data)
    insert(root->left,item)//CTE, no semicolon here
  return root;
}

int main(void){
  int list[] = {15,3,2};
  Node* root = NULL;
  for(int i = 0;i < 13;i++){
    root = insert(root,list[i]);//CTE
  }
  return 0;
}
