//here we need to construct the tree when inorder and preorder are given
//IMP->we can construct tree only when out of 2 traversals one traversal is Inorder
//so we can construct only when   1.Inorder+preorder  2.Inorder+postorder
#include<bits/stdc++.h>
using namespace std;
//to be done
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

int main()
{
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(20);
	root->right->left=new Node(30);
	root->right->right=new Node(35);
    
    return 0;
}

                        
