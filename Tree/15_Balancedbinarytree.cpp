#include<bits/stdc++.h>
using namespace std;
//In a Balanced Binary Tree for every node, 
//the difference between heights of left subtree and right subtree should not be more than one.
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
//o(n)
int height(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return max(height(root->left),height(root->right))+1;
}
// Naive solun 
//Time->o(n*n){height is o(n) and we are calling height for Ll nodes except root so overall time On*n}
bool isBalanced(Node *root)
{
    if(root==NULL)
        return true;
    int lh=height(root->left);
    int rh=height(root->right);

    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

//Efficient solution o(n) VIMP
//This function returns integer which if it is negative means not balanced and if it is poitive then it returns height
//check the working of it using diagram
int isBalancedoptimised(Node *root)
{
    if(root==NULL)
        return 0;
    int lh=isBalancedoptimised(root->left);//check for the left subtree also get the height
    if(lh==-1)
        return -1;
    int rh=isBalancedoptimised(root->right);//check for the right subtree also get the height
    if(rh==-1)
        return -1;
    if(abs(lh-rh)>1)//at the end we check the current node is balanced or not
        return -1;
    else
        return(max(lh,rh)+1);

}

int main()
{
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
	cout<<"Naive->"<<isBalanced(root)<<endl;
	cout<<"Optimised->"<<isBalancedoptimised(root);
	// cout<<isCsum(root);
    return 0;
}

                        
