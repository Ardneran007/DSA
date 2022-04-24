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
//space->O(n)//here we need O(n)space not O(h) so this requires more space
void preorder_iterative(Node *root)
{
    if(root==NULL)//we first check the corner case 
        return;
    stack<Node *>s;
    s.push(root);
    while(s.empty()==false)
    {
        Node *curr=s.top();
        cout<<curr->key<<" ";
        s.pop();//take out the pop and enqueu its right and left childs
        if(curr->right!=NULL)//here we push right first as we want left at the top
            s.push(curr->right);
        if(curr->left!=NULL)
            s.push(curr->left);
    }
}
void preorder_recursive(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder_recursive(root->left);
        preorder_recursive(root->right); 
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
    preorder_recursive(root);
    cout<<"\niterative\n";
    preorder_iterative(root);
    return 0;
}

                        
