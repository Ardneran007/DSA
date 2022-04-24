#include<bits/stdc++.h>
using namespace std;
//methid 1 inorder traversal 
//FACT->Inorder traversal of a BST is always sorted
/*
1.Do inorder traversal of an array BST and store it in array 
2.use two pointer approach to find array has pair with given sum
//time-theta(n)
//space->theta(h+n)
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
void treetoList(Node *root,vector<int> &v)
{
    if(root==NULL)
        return;
    treetoList(root->left,v);
    v.push_back(root->key);
    treetoList(root->right,v);
}
bool isPairPresent(Node *root,int sum)
{
    vector<int> a;
    treetoList(root,a);
    int start=0,end=a.size()-1;
    while(start<end)
    {
        if(a[start]+a[end]==sum){
            cout<<"Pair found "<<a[start]<<" + "<<a[end]<<" = "<<sum;
            return true;
        }
        else if(a[start]+a[end]>sum)
        {
            end--;
        }
        else if(a[start]+a[end]<sum)
        {
            start++;
        }
    }
    cout<<"NO pair ";
    return false;
}
//this approach can also work for normal tree
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
    cout<<"TREE INORDER TRAVERSAL->\n";
     inorder(root);   
     cout<<"\n";
    isPairPresent(root,sum);
    cout<<"optimised method using hashing-\n";
    if(isPairsum_optimised(root,sum,s))
        cout<<"present";
    else
        cout<<"not present";
    
    return 0;
}