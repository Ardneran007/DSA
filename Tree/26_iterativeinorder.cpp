#include<bits/stdc++.h>
using namespace std;

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
//time->O(n)
//space->O(h)
void inorder_iterative(Node *root)
{
    stack<Node *>s;
    Node *curr=root;
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        //here curr must be NULL
        //here top of stack will contain leftmost node
        curr=s.top();//take out a item
        s.pop();
        cout<<curr->key<<" ";//print it
        curr=curr->right;   //go to right side
    }
}
void inorder_recursive(Node *root)
{
    if(root!=NULL)
    {
        inorder_recursive(root->left);
        cout<<root->key<<" ";
        inorder_recursive(root->right); 
    }
}
int main()
{
   	Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    cout<<"recursive\n";
    inorder_recursive(root);
    cout<<"\niterative\n";
    inorder_iterative(root);
    return 0;
}

                        
