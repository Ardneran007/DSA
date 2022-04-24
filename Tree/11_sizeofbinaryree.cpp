//IMp check working and diagram
#include<bits/stdc++.h>
using namespace std;
//Time complexity-> O(n)
//auxiliary space->O(h) Maximum number of function calls is height+1
//Size of Binary Tree is the total numbers of nodes present in that Tree.

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
//For iterative solution use level order transversal
//Recurrsive
int getSize(Node *root)
{
    if(root==NULL)
        return 0;
    else{
        return (getSize(root->left)+getSize(root->right)+1);//standard recurrsion 
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
    cout<<"size is "<<getSize(root);
    return 0;
}

                        
