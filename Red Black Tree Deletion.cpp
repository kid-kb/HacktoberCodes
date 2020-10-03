// Red black tree Deletion

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

node* deleteNode(node *root, int val);
node* bstDeletion(node* root, int val);
node* minValueNode(node* root);
node* leftRotate(node* root, node *a);
node* rightRotate(node* root, node *a);
void preOrder(node *root);

int main()
{
    node* root = new node(50);
    root->color = false;
    
    root->left = new node(30);
    root->left->color = false;
    root->left->parent = root;
    
    root->left->left = new node(15);
    root->left->left->color = false;
    root->left->left->parent = root->left;
    
    root->left->right = new node(35);
    root->left->right->color = false;
    root->left->right->parent = root->left;
    
    root->right = new node(65);
    root->right->color = false;
    root->right->parent = root;
    
    root->right->left = new node(55);
    root->right->left->color = false;
    root->right->left->parent = root->right;
    
    root->right->right = new node(70);
    root->right->right->parent = root->right;
    
    root->right->right->left = new node(68);
    root->right->right->left->color = false;
    root->right->right->left->parent = root->right->right;
    
    root->right->right->right = new node(80);
    root->right->right->right->color = false;
    root->right->right->right->parent = root->right->right;
    
    root->right->right->right->right = new node(90);
    root->right->right->right->right->parent = root->right->right->right;
    
    //              50(0) 
    //           /       \
    //      30(0)        65(0)
    //    /     \       /   \
    //   15(0) 35(0) 55(0)  70(1)
    //                     /   \
    //                  68(0)  80(0)
    //                          \
    //                          90(1)
    preOrder(root);
    cout<<endl<<endl;
    
    cout<<"Deleting 55"<<endl;
    root = deleteNode(root, 55);
    //              50(0) 
    //           /       \
    //      30(0)        70(0)
    //    /     \       /    \
    //   15(0) 35(0)  65(0)  80(0)
    //                  \      \
    //                  68(1)  90(1)
    preOrder(root);
    cout<<endl<<endl; 
    
    cout<<"Deleting 30"<<endl;
    root = deleteNode(root, 30);
    //              50(0) 
    //           /       \
    //      35(0)        70(1)
    //      /           /    \
    //    15(1)       65(0)  80(0)
    //                  \      \
    //                  68(1)  90(1)
    preOrder(root);
    cout<<endl<<endl; 
    
    cout<<"Deleting 90"<<endl;
    root = deleteNode(root, 90);
    //              50(0) 
    //           /       \
    //      35(0)        70(1)
    //      /           /    \
    //    15(1)       65(0)  80(0)
    //                  \      
    //                  68(1)  
    preOrder(root);
    cout<<endl<<endl; 
    
    cout<<"Deleting 80"<<endl;
    root = deleteNode(root, 80);
    //             50(0) 
    //           /      \
    //        35(0)    68(1)
    //        /       /    \
    //     15(1)    65(0)  70(0)
    preOrder(root);
    cout<<endl<<endl; 
    
    cout<<"Deleting 50"<<endl;
    root = deleteNode(root, 50);
    //           65(0) 
    //        /       \
    //      35(0)    68(0)
    //      /          \
    //    15(1)       70(1)
    preOrder(root);
    cout<<endl<<endl; 
    
    cout<<"Deleting 35"<<endl;
    root = deleteNode(root, 35);
    //           65(0) 
    //        /       \
    //      15(0)    68(0)
    //                 \
    //                70(1)
    preOrder(root);
    cout<<endl<<endl; 
    
    cout<<"Deleting 15"<<endl;
    root = deleteNode(root, 15);
    //          68(0) 
    //        /       \
    //      65(0)     70(0)
    preOrder(root);
    cout<<endl<<endl; 
    
    
    return 0;
}

node* deleteNode(node *root, int val)
{
    // bst deletion return the node to be removed, it is gurranted to be a leaf node
    node* deletedNode = bstDeletion(root, val);
    
    // only root node
    if(deletedNode==root)
    {
        free(deletedNode);
        return NULL;
    }
    
    // if node to be deleted is red, simply delete it
    if(deletedNode->color)
    {
        if(deletedNode->parent->left == deletedNode)
            deletedNode->parent->left = NULL;
        else
            deletedNode->parent->right = NULL;
        free(deletedNode);
        return root;
    }
    
    node* doubleBlack = deletedNode;
    
    node *parent, *sibling, *siblingFarChild, *siblingNearChild;
    bool isDbDirectionLeft;
    
    while(doubleBlack)
    {
        // if root is double black, no problem, it will become single black
        if(doubleBlack==root)
            break;
        
        // find the parent  
        parent = doubleBlack->parent;
        // find the sibling
        if(doubleBlack == parent->left)
            sibling = parent->right;
        else
            sibling = parent->left;
        
        // find the direction of double black node
        if(doubleBlack==parent->left)
            isDbDirectionLeft = true;
        else
            isDbDirectionLeft = false;
        
        // find sibling's far child and near child
        if(sibling)
        {
            if(isDbDirectionLeft)
            {
                siblingFarChild = sibling->right;
                siblingNearChild = sibling->left;
            }
            else
            {
                siblingFarChild = sibling->left;
                siblingNearChild = sibling->right;
            }
        }
        else
        {
            siblingFarChild = NULL;
            siblingNearChild = NULL;
        }
        
        
        
        // if sibling is red
        if(sibling && sibling->color)
        {
            // swap colors of parent and sibling
            swap(parent->color, sibling->color);
            
            // rotate the parent in direction of db
            if(isDbDirectionLeft)
                root = leftRotate(root, parent);
            else
                root = rightRotate(root, parent);
                
            // reapply cases
            
        }
        // if sibling is black and both sibling children are black
        else if(!sibling || (!sibling->color && (!sibling->left || !sibling->left->color) && (!sibling->right || !sibling->right->color)))
        {
            // make the sibling red
            sibling->color = true;
            
            // give black to the parebt
            // if parent is red, simply make it black and its done
            if(parent->color)
            {
                parent->color = false;
                break;
            }
            // if parent is black, make it double black and reapply cases
            else
            {
                doubleBlack = parent;
            }
        }
        // sibling is black, sibling's far child is black and sibling's near child is red
        else if(!sibling->color && (!siblingFarChild || !siblingFarChild->color) && (siblingNearChild && siblingNearChild->color))
        {
            // swap the color of sibling and its near child
            swap(sibling->color, siblingNearChild->color);
            
            // rotate the sibling in direction away from db
            if(isDbDirectionLeft)
                root = rightRotate(root, sibling);
            else
                root = leftRotate(root, sibling);
        }
        
        // sibling is black, sibling's far child is red
        else if(!sibling->color && (siblingFarChild && siblingFarChild->color))
        {
            // swap the color of parent and the sibling
            swap(sibling->color, parent->color);
            
            // rotate the parent in direction of db
            if(isDbDirectionLeft)
                root = leftRotate(root, parent);
            else
                root = rightRotate(root, parent);
                
            // make the farchild black, and then db will be removed
            siblingFarChild->color = false;
            break;
        }
    }
    if(deletedNode->parent->left == deletedNode)
        deletedNode->parent->left = NULL;
    else
        deletedNode->parent->right = NULL;
    free(deletedNode);
    
    return root;
}   

node* bstDeletion(node* root, int val)
{
    if(root==NULL)
    {
        cout<<"Value not found !!"<<endl;
        return root;
    }
    if(val < root->data)
        return bstDeletion(root->left, val);
    if(val > root->data)
        return bstDeletion(root->right, val);
    
    if(root->left==NULL && root->right==NULL)
        return root;
    if(root->left==NULL || root->right==NULL)
    {
        node* child = root->left? root->left : root->right;
        root->data = child->data;
        return bstDeletion(child, child->data);
    }
    node* successor = minValueNode(root->right);
    root->data = successor->data;
    return bstDeletion(successor, successor->data);
    
}

node* minValueNode(node* root)
{
    if(root==NULL)
        return root;
    node* curr = root;
    while(curr->left!=NULL)
        curr = curr->left;
    return curr;
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