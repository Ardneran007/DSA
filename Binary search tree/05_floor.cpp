#include<bits/stdc++.h>
using namespace std;
//Floor-closest smaller or equal value

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
//Naive->traverse 

//optimised->Time->O(h) space>O(1)
//begin with root and follow NORMAL BST search
//1.if root is same as key return root
//2. if root is greater floor has to to lie in left subtree
//3.if root is smaller then root itself can be a potentioal floor and floor can also be in right subtree
//Time->O(h) 
//space>O(1)
Node *floor(Node *root,int x)
{
    Node *res=NULL;
    while(root!=NULL)
    {
        if(root->key==x)
        {
            return root;
        }
        else if(root->key>x)
        {
            root=root->left;
        }
        else
        {
            //root->key<x
            res=root;
            root=root->right;
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
	
	cout<<"Floor: "<<(floor(root,17)->key);
    return 0;
}