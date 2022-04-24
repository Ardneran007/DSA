#include<bits/stdc++.h>
using namespace std;
//ceil->value in BST which is greater than or equal

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
//optimised
//initialise res as NULL and traverse from root and follow
/*
1.if root key is same as x return root
2.if root key is smallest then change root to root's right
3.if root's key is greater update the res as root and change root to roots left
*/
//Time->O(h)
//space->O(1)
Node *ceil(Node *root,int x)
{
    Node *res=root;
    while(root!=NULL)
    {
        if(root->key==x)
            return root;
        else if(root->key<x)
            root=root->right;
        else
        {
            res=root;//root having potential for the answer
            root=root->left;
        }
    }
    return res;
}
int main()
{
    Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=17;
	cout<<"Ceil: "<<(ceil(root,17)->key);   
    return 0;
}
