#include<bits/stdc++.h>
using namespace std;
//if height is completely balanced height can become logn
//BUT if tree is skewed then height is n worst case
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
//NOTE FOR SELF BAlancing trees time comes out to be 
//o(logn)
//time->O(h)
//space->for func call stack O(h)
bool search(Node *root,int x)
{
    if(root==NULL)
        return false;
    else if(root->key==x)
        return true;
    else if(root->key>x)
        return search(root->left,x);
    else
        return search(root->right,x);
}
//iterative (better)
//time->O(h)
//space->O(1)
bool search_iterative(Node *root,int x)
{
    while(root!=NULL)
    {
        if(root->key==x)
            return true;
        else if(root->key<x)
            root=root->right;
        else
            root=root->left;
    }
    return false;
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
	int x=16;
	
	if(search(root,x))
	    cout<<"Found\n";
	else
	    cout<<"Not Found\n";

    if(search_iterative(root,x))
	    cout<<"Found iteratively :)";
	else
	    cout<<"Not Found iteratively :)";
}