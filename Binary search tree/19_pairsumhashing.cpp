#include<bits/stdc++.h>
using namespace std;
//Method 2 using hashing
/*
to be done 
time->o(n)
space->O(n)
also check the stack based solution
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
//this approach can also work for normal tree
//time->O(n)
//space->O(h+n)~O(n)
bool isPairsum_optimised(Node *root,int sum,unordered_set<int> &s)
{
    if(root==NULL)
        return false;
    if(isPairsum_optimised(root->left,sum,s)==true)
        return true;
    if(s.find(sum-root->key)!=s.end())
        return true;
    else
        s.insert(root->key);
    return (isPairsum_optimised(root->right,sum,s));
}

int main()
{
    Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);
    unordered_set<int> s;
    int sum=33;
    cout<<"optimised method-\n";
    if(isPairsum_optimised(root,sum,s))
        cout<<"present";
    else
        cout<<"not present";
    
    return 0;
}

