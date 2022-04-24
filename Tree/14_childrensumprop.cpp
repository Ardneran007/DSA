#include<bits/stdc++.h>
using namespace std;
//Time complexity-> O(n)
//auxiliary space->O(height) at 

// Children Sum Property is a property in which the sum of values of the left child and right child should be equal to the value of their node if both children are present. 
// Else if only one child is present then the value of the child should be equal to its node value.

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
bool isCsum(Node *root)
{
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)//imp condition(as if there is a single leaf node we consider the answer a true)
        return true;//this is most imp corner case
    int sum=0;//t->left!=NULL)
    {
        sum+=root->left->key;
    }
    if(root->right!=NULL)
    {
        sum+=root->right->key;
    }
    return ((root->key==sum) && isCsum(root->right) && isCsum(root->left) );//just check 3 conditions
    //1.sum=root->left+root->right
    //2.this property is true for left subtree
    //3.this property is true for right subtree
}
int main()
{
    Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(12);
	root->right->left=new Node(3);
	root->right->right=new Node(9);
	
	cout<<isCsum(root);
    return 0;
}

                        
