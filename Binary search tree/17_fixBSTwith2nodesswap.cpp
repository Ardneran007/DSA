#include<bits/stdc++.h>
using namespace std;
//to be done//?
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
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

Node *prev=NULL,*first=NULL,*second=NULL;
void fixBST(Node *root,Node *prev,Node *first,Node *second)
{
    if(root==NULL)
        return;
    fixBST(root->left,prev,first,second);
    if(prev!=NULL && root->key<prev->key)
    {
        if(first==NULL)
            first=prev;
        second=root;
    }
    prev=root;

    fixBST(root->right,prev,first,second);
}
void correctBST(Node *root)
{
    Node *prev=NULL,*first=NULL,*second=NULL;
    fixBST(root,prev,first,second);

}
int main()
{
    	Node *root = new Node(18);  
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80);  
    
    inorder(root); 
    cout<<endl;
    fixBST(root,NULL,NULL,NULL);
    int temp=first->key;
    first->key=second->key;
    second->key=temp;
    inorder(root);
    return 0;
}