// Red black tree

#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *left=NULL, *right=NULL, *parent=NULL;
    bool color=true;
    // red color = true
    // black color = false
    node(int data)
    {
        this->data = data;
    }
}node;

node* insert(node *root, int val);
node* bstInsertion(node* root, node* newNode);
node* leftRotate(node* root, node *a);
node* rightRotate(node* root, node *a);
void preOrder(node *root);

int main()
{
   
   node* root = NULL;
   
   cout<<"Inserting 10"<<endl;
   root = insert(root, 10);
   //       10(0)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 18"<<endl;
   root = insert(root, 18);
   //       10(0)
   //           \
   //           18(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 7"<<endl;
   root = insert(root, 7);
   //       10(0)
   //      /    \
   //    7(1)   18(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 15"<<endl;
   root = insert(root, 15);
   //       10(0)
   //      /    \
   //    7(0)   18(0)
   //          /
   //        15(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 16"<<endl;
   root = insert(root, 16);
   //       10(0)
   //      /    \
   //    7(0)  16(0)
   //         /    \
   //       15(1)  18(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 30"<<endl;
   root = insert(root, 30);
   //       10(0)
   //      /    \
   //    7(0)  16(1)
   //         /    \
   //       15(0)  18(0)
   //               \
   //               30(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 25"<<endl;
   root = insert(root, 25);
   //       10(0)
   //      /    \
   //    7(0)  16(1)
   //         /    \
   //       15(0)  25(0)
   //             /   \
   //           18(1) 30(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 40"<<endl;
   root = insert(root, 40);
   //          16(0)
   //        /       \
   //     10(1)      25(1)
   //    /   \      /    \
   //  7(0) 15(0) 18(0) 30(0)
   //                      \
   //                    40(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 60"<<endl;
   root = insert(root, 60);
   //          16(0)
   //        /       \
   //     10(1)      25(1)
   //    /   \      /    \
   //  7(0) 15(0) 18(0) 40(0)
   //                   /   \
   //                 30(1) 60(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 2"<<endl;
   root = insert(root, 2);
   //           16(0)
   //         /       \
   //      10(1)      25(1)
   //     /   \      /    \
   //   7(0) 15(0) 18(0) 40(0)
   //  /                 /   \
   // 2(1)             30(1) 60(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 1"<<endl;
   root = insert(root, 1);
   //           16(0)
   //         /       \
   //      10(1)      25(1)
   //     /   \      /    \
   //   2(0) 15(0) 18(0) 40(0)
   //  /   \             /   \
   // 1(1) 7(1)        30(1) 60(1)
   preOrder(root);
   cout<<endl<<endl;
   
   cout<<"Inserting 70"<<endl;
   root = insert(root, 70);
   //            16(0)
   //         /       \
   //      10(0)      25(0)
   //     /   \      /    \
   //   2(0) 15(0) 18(0) 40(1)
   //  /   \             /   \
   // 1(1) 7(1)        30(0) 60(0)
   //                         \
   //                        70(1)
   preOrder(root);
   cout<<endl<<endl;
   
   return 0;
}

node* insert(node *root, int val)
{
    node* newNode = new node(val);

    // in case of empty tree, make this node black
    if(root==NULL)
    {
        newNode->color = false;
        root = newNode;
        return root;
    }
    
    // perform normal bst insertion
    root = bstInsertion(root, newNode);

    node *curr = newNode;
    node *parent, *grandParent, *uncle;
    
    // check if there is a double red problem
    // while curr node is colored red and its parent is also colored red
    while(curr->color && curr->parent->color)
    {
        parent = curr->parent;
        grandParent = parent->parent;

        if(parent==grandParent->left)
            uncle = grandParent->right;
        else
            uncle = grandParent->left;
         
        // if uncle is colored red, then only recoloring is required and check again the grandparent   
        if(uncle && uncle->color)
        {
            parent->color = false;
            uncle->color = false;
            if(grandParent!= root)
                grandParent->color = true;
            curr = grandParent;
        }
        // else the uncle is null or block, then rotation and recoloring both are required
        else
        {
            if(parent==grandParent->left && curr==parent->left)
            {
                // LL imbalance
                root = rightRotate(root, grandParent);
                parent->color = !(parent->color);
                grandParent->color = !(grandParent->color);
            }
            else if(parent==grandParent->right && curr==parent->right)
            {
                // RR imbalance
                root = leftRotate(root, grandParent);
                parent->color = !(parent->color);
                grandParent->color = !(grandParent->color);
            }
            else if(parent==grandParent->left && curr==parent->right)
            {
                // LR imbalance
                root = leftRotate(root, parent);
                root = rightRotate(root, grandParent);
                curr->color = !(curr->color);
                grandParent->color = !(grandParent->color);
                
            }
            else
            {
                // RL imbalance
                root = rightRotate(root, parent);
                root = leftRotate(root, grandParent);
                curr->color = !(curr->color);
                grandParent->color = !(grandParent->color);
            
            }
            return root;
        }
    }
    
    return root;
}

node* bstInsertion(node* root, node* newNode)
{
    if(root==NULL)
        return newNode;
    if(newNode->data < root->data)
    {
        root->left = bstInsertion(root->left, newNode);
        root->left->parent = root;
    }
    else if(newNode->data > root->data)
    {
        root->right = bstInsertion(root->right, newNode);
        root->right->parent = root;
    }
    else
        cout<<"Duplicate values not allowed !! "<<endl;
    return root;
}

node* leftRotate(node* root, node *a)
{
    node *a_old_parent = a->parent;
    node *b = a->right;
    node *bl = b->left;
    
    b->left = a;
    a->right = bl;
    
    b->parent = a_old_parent;
    a->parent = b;
    if(bl)
        bl->parent = a;
        
    if(a_old_parent==NULL)
        root = b;
    else if(a_old_parent->right==a)
        a_old_parent->right = b;
    else
        a_old_parent->left = b;
    
    return root;
}

node* rightRotate(node* root, node *a)
{
    node *a_old_parent = a->parent;
    node *b = a->left;
    node *br = b->right;
    
    b->right = a;
    a->left =  br;
    
    b->parent = a_old_parent;
    a->parent = b;
    if(br)
        br->parent = a;
    if(a_old_parent == NULL)
        root = b;
    else if(a_old_parent->left == a)
        a_old_parent->left = b;
    else
        a_old_parent->right = b;
    return root;
}

void preOrder(node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<"("<<root->color<<")";
    if(root->parent)
        cout<<"("<<root->parent->data<<") ";
    else
        cout<<' ';
    preOrder(root->left);
    preOrder(root->right);
}