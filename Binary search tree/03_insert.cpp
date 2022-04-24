#include<bits/stdc++.h>
using namespace std;
//in insert we first search the given number is present or not
//so INSERTION=SEARCHING + CREATING LINKS
//if yes then dont do anything and if no then insert a new leaf
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

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
} 
//ITERATIVE IS BETTER THAN RECURSSIVE

//Insertion always happen at the bottom root is not changes it is changed
//only in one case ie when the root is empty

//time-O(h)
//space-O(h)
Node *insert_recursive(Node *root,int x)
{
    if(root==NULL)
        return new Node(x);//a.whenever we get NULL we create new leaf using it but now we need to link it
    else if(root->key<x)
        root->right=insert_recursive(root->right,x);//this is imp(returning value back to right){/*b.this is to link the new leaf and this also overwrites previous links*/}
    else
        root->left=insert_recursive(root->left,x);//this is imp(returning value back to left)
    return root;
}

//iterative is lengthy as we need to connect leaf with the parent
//time-O(h)
//space-O(1)
Node *insert_iterative(Node *root,int x)
{
    Node *temp=new Node(x);
    Node *parent=NULL;//to keep track of parent and to link it with child
    Node *curr=root;
    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else
            return root;
    }//end of loop at this time curr must be NULL

    if(parent==NULL)//this is to check whether it has gone in while loop{ie if the tree is empty or not}
        return temp;
    if(parent->key>x)
        parent->left=temp;
    else
        parent->right=temp;
    return root;
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(12);
	root->right->right=new Node(18);
	int x=20;
	
	root=insert_iterative(root,x);//iterative is better than recurrsive
	inorder(root);

    return 0;
}