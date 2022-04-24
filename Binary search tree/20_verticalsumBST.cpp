#include<bits/stdc++.h>
using namespace std;
/*
time->for traversal->O(nloght) ht->total number of possible horizontal distances
for wrapper->O(ht)
so 
TOTAL TIME->O(nloght + ht)~ O(nloght)

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
//ht->horizontal distance wrt root
void vertical_sum(Node *root,int ht,map<int,int> &m)
{
    if(root==NULL)
        return;
    vertical_sum(root->left,ht-1,m);
    m[ht]+=root->key;
    vertical_sum(root->right,ht+1,m);
}
//wrapper function
void V_SUM(Node *root)
{
    map<int,int> mp;
    vertical_sum(root,0,mp);
    for(auto sum : mp)
    {
        cout<<(sum.second)<<" ";
    }
}
int main()
{
    Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(50);  
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    V_SUM(root);
   
    return 0;
}