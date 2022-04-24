//Level order traversal of a tree is breadth first traversal of binary tree.
//recursion is not a good choice here
#include<bits/stdc++.h>
using namespace std;
//Time complexity->theta(n)
//auxiliary space->o(w)
//Interesting fact-->In Queue there is atmst 1 level at a time
//so to be precise auxiliary space of queue is width of tree.
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

void printLevel(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        Node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
    printLevel(root);
    return 0;
}
/*
              10
        20          30
      40  50          70
                         80  
                         */
                        
