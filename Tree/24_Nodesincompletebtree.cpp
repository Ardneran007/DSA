#include<bits/stdc++.h>
using namespace std;
//MOST IMP_>ANALYSE TIME COMPLEXITY AS EXPLAINED logn*logn
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
//Naive solution O(n) works for any tree
int countNode(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return 1+ countNode(root->left)+countNode(root->right);
}
//optimised solution
//this uses that i/p tree is complete binary tree
//TIME->log(n)*log(n)
//check the working of this by diagram

//to check whether the subtree is perfectly balanced  we go left left left and right right right... 
//if they are on same level then subtree is perfectly balancd 

//BeST CASE->perfect binary tree 1 2 4 8...
//worst case
int countNode_optimised(Node *root)
{
    int lh=0,rh=0;
    Node *curr=root;
    while(curr!=NULL)
    {
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr!=NULL)
    {
        rh++;   
        curr=curr->right;
    }
    if(lh==rh)
    {
        return pow(2,lh) -1;
    }
    return 1+countNode_optimised(root->left)+countNode_optimised(root->right);//one of these calls will fall into best casee

}
int main()
{   //Constraint->the given tree must be a complete binary tree
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	cout<<countNode(root)<<"\n";
    cout<<"using optimised solution- "<<countNode_optimised(root);

    return 0;
}

                        
