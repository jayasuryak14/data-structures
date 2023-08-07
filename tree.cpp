#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void push(int data) {
    //TreeNode* root = createNode(1);
    //root->left = createNode(2);
    //root->right = createNode(3);
   // root->left->left = createNode(4);
    //root->left->right = createNode(5);
    //printf("the inserted nodes are:",root);
    //printf("\n");
  //  return 0;
  push(10);
  return 0;
}
