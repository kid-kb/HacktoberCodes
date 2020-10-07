#include <stdio.h>
#include <stdlib.h>
 
// Define the types of Traversals here
enum Traversal {PREORDER, INORDER, POSTORDER};
 
typedef enum Traversal Traversal;
typedef struct Node Node;
 
// Define the Tree Node here
struct Node {
    int value;
    // Pointers to the left and right children
    Node* left, *right;
};
 
 
Node* init_tree(int data) {
    // Creates the tree and returns the
    // root node
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}
 
Node* create_node(int data) {
    // Creates a new node
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}
void free_tree(Node* root) {
    // Deallocates memory corresponding
    // to every node in the tree.
    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}
 
 
void print_tree(Traversal traversal, Node* root) {
    // Prints the tree according to
    // various types of traversals
    if (!root)
        return;
    switch(traversal) {
        case (PREORDER):
            // Do a Preorder Traversal
            printf("%d -> ", root->value);
            print_tree(traversal, root->left);
            print_tree(traversal, root->right);
            break;
 
        case (INORDER):
            // Do an Inorder Traversal
            print_tree(traversal, root->left);
            printf("%d -> ", root->value);
            print_tree(traversal, root->right);
            break;
 
        case (POSTORDER):
            // Do a postorder Traversal
            print_tree(traversal, root->left);
            print_tree(traversal, root->right);
            printf("%d -> ", root->value);
            break;
    }
}
 
int main() {
    // Program to demonstrate finding the height of a Binary Tree
 
    // Create the root node having a value of 10
    Node* root = init_tree(10);
     
    // Insert nodes onto the tree
    root->left = create_node(20);
    root->right = create_node(30);
 
    root->left->left = create_node(40);
    root->left->right = create_node(50);
 
    root->right->left = create_node(60);
    root->right->right = create_node(70);
 
    printf("----Preorder Traversal:----\n");
    print_tree(PREORDER, root);
    printf("\n\n");
 
    printf("----Inorder Traversal:----\n");
    print_tree(INORDER, root);
    printf("\n\n");
 
    printf("----Postorder Traversal:----\n");
    print_tree(POSTORDER, root);
    printf("\n\n");
 
    // Free the tree!
    free_tree(root);
    return 0;
}
