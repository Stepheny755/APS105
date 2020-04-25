#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
  int value;
  struct node* left;
  struct node* right;
}Node;

typedef struct bstree{
  Node* root;
}BSTree;

void printTree(Node* root,int depth)
{
    if (root == NULL){
        return;
    }
    printTree(root->right,depth+1);
    printf("\n");
    for(int i =0;i<depth;i++){
      printf("   ");
    }
    if(root->value<10){
      printf(" ");
    }
    printf("%d\n",root->value);
    printTree(root->left,depth+1);
}

Node* createNode(int value){
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

BSTree* createTree(int value){
  BSTree* temp = (BSTree*)malloc(sizeof(BSTree));
  temp->root = createNode(value);
  return temp;
}

void insertValue(Node* root,int value){
  if(value>root->value){
    if(root->right==NULL){
      root->right=createNode(value);
    }else{
      insertValue(root->right,value);
    }
  }
  if(value<root->value){
    if(root->left==NULL){
      root->left=createNode(value);
    }else{
      insertValue(root->left,value);
    }
  }
}


bool insert(BSTree *tree, int value){
  insertValue(tree->root,value);
  return true;
}




int main(){

  BSTree* new = createTree(10);
  insert(new,5);
  insert(new,6);
  insert(new,7);
  insert(new,4);
  insert(new,11);
  insert(new,12);
  insert(new,8);
  insert(new,16);
  insert(new,14);
  insert(new,3);
  insert(new,1);
  insert(new,2);
  printTree(new->root,0);



}
