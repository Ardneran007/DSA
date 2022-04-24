#include<bits/stdc++.h>
using namespace std;
//Method-1
/*
sort the preorder and get inorder and do the algo for getting BT from inorder and preorder
Time->O(nlogn)+O(n)
Space->O(n)
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
void preorder(Node *root)
{
    if(root==NULL)
        return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}
//Here we only pass upperbound there is no need of lower bound(VIMP)
/*
1,If we are going left bound should be node value
2.If we are going right we must transfer the bound
Time->O(3*n)~O(n)
space->recursion stack 
*/
Node *build(int A[],int size,int &i,int bound)
{
    if(i==size || A[i]>bound)//out of bound or elements over
        return NULL;
    Node *root=new Node(A[i++]);
    root->left=build(A,size,i,root->key);//adjust the bound
    root->right=build(A,size,i,bound);//bound remain same
    return root;
}
Node* BSTfrompreorder(int A[],int size)
{
    int i=0;
    return build(A,size,i,INT_MAX);
}


int main()
{
    /*
    10
   /   \
  5     40
 /  \      \
1    7      50 */
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
    Node *root=BSTfrompreorder(pre,size);
    cout<<"inorder\n";
    inorder(root);
    cout<<"\nPreorder\n";
    preorder(root);   
    return 0;
}