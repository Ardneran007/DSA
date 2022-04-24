#include<bits/stdc++.h>
using namespace std;
//Time->o(n)
//Auxiliary space->o(height of binary tree)/o(h)
//see the diagram how it works
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
};

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<(root->key)<<" ";
        inorder(root->right);
    }
}
int main()
{
    Node *root=new Node(1);
    root->right=new Node(2);
    root->right->left=new Node(3);
    root->right->left->right=new Node(4);
    root->right->left->left=new Node(5);
    root->right->left->left->left=new Node(6);
    root->right->left->left->right=new Node(7);

    inorder(root);
    return 0;
}