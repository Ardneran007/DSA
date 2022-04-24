#include<bits/stdc++.h>
using namespace std;
//Nodes at distance k from the root are basically the nodes at (k+1)th level of the Binary Tree.
//time->o(n)
//        best o(1) worst o(n)
//auxiliary space->o(h)
//        worst o(h)
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

void printDist(Node *root,int k)
{
    if(root==NULL)//this must be the 1st condn
        return;
    if(k==0)//this must be 2nd condition
    {
        cout<<(root->key)<<" ";
    }
    else
    {
        printDist(root->left,k-1);
        printDist(root->right,k-1);
    }
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
    printDist(root,2);
    return 0;
}
/*
              10
        20          30
      40  50          70
                         80  
                         */
                        