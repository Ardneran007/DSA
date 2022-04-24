#include<bits/stdc++.h>
using namespace std;
//method 1 inorder traversal 
//FACT->Inorder traversal of a BST is always sorted
/*
1.Do inorder traversal of an array BST and store it in array 
2.use two pointer approach to find array has pair with given sum
//time-theta(n)
//space->theta(h+n)
*/
struct Node
{
    int key;
    Node *left,*right;
    Node(int x)
    {
        key=x;
        left=right=NULL;
    }
};
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
//optimised
Node *inordersuccessor(Node *root,Node * p)
{
    Node *successor=NULL;
    while(root!=NULL)
    {
        if(p->key>=root->key)
            root=root->right;
        else
        {
            successor=root;//this could be the possible answer
            root=root->left;
        }
    }
    return successor;
}
int main()
{
    Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);
    inorder(root);
    cout<<"\n";
    Node *temp=inordersuccessor(root,root->left->left);
    root->right->right->left->right = temp;
    inorder(root);
    
    return 0;
}