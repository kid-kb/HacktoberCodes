// Author name: Muskaan Rajput
// Date: 2 October 2022
// Bio: B.Tech, 3rd year cse student

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *Take_Input_Level_Wise()
{
    cout << "Enter root data: " << endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cout << "Enter left child data value of " << front->data << " : " << endl;
        cin >> leftChildData;

        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChildNode = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChildNode;
            pendingNodes.push(leftChildNode);
        }

        int rightChildData;
        cout << "Enter right child data value of " << front -> data << " : " << endl;
        cin >> rightChildData;

        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChildNode = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChildNode;
            pendingNodes.push(rightChildNode);
        }
    }
    return root;
}

void print_Level_Wise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << " : ";

        if(front -> left != NULL)
        {
            cout<<"L : "<<front -> left -> data<<" , ";
            pendingNodes.push(front -> left);
        }
        else
        {
            cout<<"L : "<<-1<<" , ";
        }


        if(front -> right != NULL)
        {
            cout<<"R : "<<front -> right -> data;
            pendingNodes.push(front -> right);
        }
        else
        {
            cout<<"R : "<<-1;
        }
        cout<<endl;
    }
}

int count_Nodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int numNodes = 1;
    int ans1 = count_Nodes(root -> left);
    int ans2 = count_Nodes(root -> right);
    return numNodes + ans1 + ans2;
}

int main()
{
    BinaryTreeNode<int> *root = Take_Input_Level_Wise();
    cout<<endl;
    cout<<"number of nodes are : "<<endl;
    cout<<count_Nodes(root);
    cout<<endl;
    print_Level_Wise(root);
    return 0;
}
