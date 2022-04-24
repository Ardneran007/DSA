#include<bits/stdc++.h>
using namespace std;

// Inorder conversion of Binary Tree to Doubly Linked List.
// A function that takes root of a Binary Tree and converts it into a Doubly linked list.
// Hint:- we need to do the inorder traversal of the Tree and while doing inorder traversal
//  we can simply maintain a previous pointer or reference of the previously traversed node.
//   And change right child of the previous node to current node and left child of current node as previous.

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
//first Node in inorder travreal must be the head of dll
// so when prev of any node is NUL it is the head of binary tree
//time->o(n)
// space->o(h)
Node *BTtoDLL(Node *root)
{
    if(root==NULL)
        return root; 
    static Node *prev=NULL;//imp()
    Node *head=BTtoDLL(root->left);
    if(prev==NULL)//this will only execute once
    {
        head=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTtoDLL(root->right);
    return head;
}

void printList(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->key<<"<=>";
        curr=curr->right;
    }cout<<endl;
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(20);
	root->right->left=new Node(30);
	root->right->right=new Node(35);
    Node *head=BTtoDLL(root);
	printList(head);
    return 0;
}

                        
