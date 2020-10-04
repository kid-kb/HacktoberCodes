#include <bits/stdc++.h> 
  
using namespace std; 
  
// Node of a binary tree 
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
  
// function to get a new node 
Node* getNode(int data) 
{ 
    // allocate memory for the node 
    Node *newNode =  
        (Node*)malloc(sizeof(Node)); 
      
    // put in the data     
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode;     
} 
  
// function to find the sum of all the  
// parent nodes having child node x 
void sumOfParentOfX(Node* root, int& sum, int x) 
{ 
    // if root == NULL 
    if (!root) 
        return; 
      
    // if left or right child of root is 'x', then 
    // add the root's data to 'sum' 
    if ((root->left && root->left->data == x) || 
        (root->right && root->right->data == x)) 
        sum += root->data; 
      
    // recursively find the required parent nodes 
    // in the left and right subtree     
    sumOfParentOfX(root->left, sum, x); 
    sumOfParentOfX(root->right, sum, x); 
      
} 
  
// utility function to find the sum of all 
// the parent nodes having child node x 
int sumOfParentOfXUtil(Node* root, int x) 
{ 
    int sum = 0; 
    sumOfParentOfX(root, sum, x); 
      
    // required sum of parent nodes 
    return sum; 
} 
  
// Driver program to test above 
int main() 
{ 
    // binary tree formation 
    Node *root = getNode(4);           /*        4        */
    root->left = getNode(2);           /*       / \       */
    root->right = getNode(5);          /*      2   5      */
    root->left->left = getNode(7);     /*     / \ / \     */
    root->left->right = getNode(2);    /*    7  2 2  3    */
    root->right->left = getNode(2); 
    root->right->right = getNode(3); 
      
    int x = 2; 
      
    cout << "Sum = "
         << sumOfParentOfXUtil(root, x); 
           
    return 0;     
}  
