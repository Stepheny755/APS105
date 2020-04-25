#include <stdio.h>
#include <stdbool.h>

typedef struct node{
  int data;
  struct node* left;
  struct node* right;
}Node;



Node* secondLargestNode(Node* root){
  bool found = false;
  Node* temp = root,super = NULL;
  while(curr->right!=NULL){
    curr=curr->right;
    super=curr;
  }
  curr = curr->left;
  while(curr->right!=NULL){
    curr=curr->right;
  }
  return curr;

}
