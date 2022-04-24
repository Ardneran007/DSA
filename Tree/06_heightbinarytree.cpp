#include<bits/stdc++.h>
using namespace std;
//height->Maximum no of nodes from root to leaf
//check the working of this in diagram(imp
//time->o(n)
//space->o(h+1)(worst case) so space is o(h)
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

int height(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return max(height(root->left),height(root->right)) + 1;//standard recursion of counting
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    cout<<"Height of tree is "<<height(root);
    return 0;
}