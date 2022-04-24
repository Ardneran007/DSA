//IMp check working and diagram
#include<bits/stdc++.h>
using namespace std;
//HERE USE THE METHOD ACC TO QUUS
//To Print Left View of Binary Tree we need to print the leftmost node at every level of the Binary Tree.
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

//IF we do preorder traversal of binary tree we would always visit lefmost node first than any other NOde
//while doing preorder traversal we maintain 2 extra variables maxlevel and level we initialize level as 1
//at any level if level is greater than maxlevel then print this Node(ie it is first Node Of this level)

//time->theta(n)
//space->theta(h)
int maxlevel=0;
void printLeftrecursive(Node *root,int level)
{
    if(root==NULL)
        return;
    if(maxlevel<level)
    {
        cout<<root->key<<" ";
        maxlevel=level;
    }
    printLeftrecursive(root->left,level+1);
    printLeftrecursive(root->right,level+1);
    
}
void printLeftview(Node *root)
{
    printLeftrecursive(root,1);
}

//iterative solution->line by line traversal methpd 2 just print node if i=0
//Time complexity->theta(n)
//space->theta(width)
void printLeftiterative(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(i==0)//if its first Node then only print it
            {
                cout<<(curr->key)<<" ";
            }
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
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
	root->right->right=new Node(60);
    printLeftiterative(root);
    cout<<endl;
    printLeftview(root);
    return 0;
}

                        
