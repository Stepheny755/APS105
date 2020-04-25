
// Question 10
//
//submit ONLY your function code. Do not submit header files, main(), structure definitions or provided functions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// A node in a binary search tree.
typedef struct node {
  int data;
  struct node *left, *right;
} Node;

// A binary search tree.
typedef struct bstree {
    Node *root;
} BSTree;

// Create a new node on the heap.
Node *createNode(int value) {
  Node *p = (Node *) malloc(sizeof(Node));

  if (p != NULL) {
    p->data = value;
    p->left = p->right = NULL;
  }
  return p;
}

// Initialize the binary search tree to be empty.
void initBSTree(BSTree *tree) {
    tree->root = NULL;
}

// Check if a tree is empty.
bool isEmpty(BSTree *tree) {
    if (tree->root == NULL) {
        return true;
    }

    return false;
}

// Recursively traverse the subtree and add a new node to the appropriate parent.
Node * insertRecursiveHelper(Node *n, int value) {
  if (n == NULL) {
    // We have reached an empty spot in the tree, create the node.
    return createNode(value); // Base case.
  }

  if (value <= n->data) {
    // The new node should go to the left of the current subtree.
    n->left = insertRecursiveHelper(n->left, value); // Recursive call.
  } else {
    // The new node should go to the right of the parent.
    n->right = insertRecursiveHelper(n->right, value); // Recursive call.
  }

  return n;
}

// Insert a new value into the tree, with recursion.
bool insertRecursive(BSTree *tree, int value) {
  // Start at the root and recursively traverse the tree.
  Node *inserted = insertRecursiveHelper(tree->root, value);

  // The root of the tree may have been updated.
  tree->root = inserted;

  return inserted != NULL;
}

void printRecursiveHelper(Node *n) {
  if (n == NULL) {
    return; // Base case.
  }

  // Print all smaller values first.
  printRecursiveHelper(n->left); // Recursive call.

  printf("%d ", n->data);

  // Print all larger values next.
  printRecursiveHelper(n->right); // Recursive call.
}

// Print the elements of the tree in order.
void printRecursive(BSTree *tree) {
  // Starting from the root, recursively traverse and print the tree in-order.
  printRecursiveHelper(tree->root);
}

// Check if the tree is skewed
bool isTreeSkewed(BSTree *tree, int n) {

  return false;
}

// Do not include the following main() function in your submitted code
int main(void) {
	//this is an example of running the function. Your function will be tested with other examples
    int list[] = {15, 3, 2, 9, 4, 30, 6, 8, 7, 1, 18, 31, 32};

    BSTree tree;
    initBSTree(&tree);

    for (int i = 0; i < 13; i ++) {
        bool inserted = insertRecursive(&tree, list[i]);

        if (!inserted) {
            printf("Could not insert node %d into the tree, exiting.\n", i);

            return 0;
        }
    }

    printf("The tree contains (in ascending order): ");
    printRecursive(&tree);
    printf("\n");

    if (isTreeSkewed(&tree, 2)) {
      printf("The tree is skewed.\n");
    } else {
      printf("The tree is not skewed.\n");
    }

    return 0;
}
