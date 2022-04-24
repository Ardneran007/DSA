#include<bits/stdc++.h>
using namespace std;
//Diameter if tree->NO of nodes in longest path b/w 2 leaf nodes
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

int height(Node *root)
{
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right)) +1;
}
//Naive solution o(n*n)
/*
traverse through every node find leftheight rightheight add 1 to it and find diameter through tis node
and recursively calls same for left subtree and right subtree and find diameter for lsubtree and rsubtree
at end it returns max of this three values
also check the diagram for it

WORST CASE->when there is a skew tree  T(N)=T(N-1)+THETA(N) ->theta(n2);
*/
int diameter(Node *root)
{
    if(root==NULL)
        return 0;
    int d1=1+height(root->left)+height(root->right);
    int d2=diameter(root->left);
    int d3=diameter(root->right);
    return max(d1,max(d2,d3));//imp
}
//NOT IMPLEMENTED YET-----
//Better solution using unordered maps
/*
    Idea is to precompute heights of every node and store it in map and after storing height in a unordered map we 
    can get it in O(1) time
    but
    this solun requires o(n) for maps and extra overhead for looking into hash table so this is not the most optimised
    //for hash maps space->o(n)
    //but for this->space->o(h)
*/

//OPTIMISED SOLUTION
//we just keep the track of diameter while computiong the height and keep it maximum
//this function returns height but sets the res variable to have diameter
//time->O(n) space->o(h)
//for hash maps space->o(n)
//but for this->space->o(h)
int res=0;//extra variable
int height_optimised(Node *root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    res=max(res,1+lh+rh);//this is extra than height function
    return 1+max(lh,rh);
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(60);
	root->right->left->left=new Node(50);
	root->right->right->right=new Node(70);
	//naive
	cout<<diameter(root)<<endl;
    cout<<"height->"<<height_optimised(root)<<endl;
    cout<<"Diameter->"<<res;
    return 0;
}

                        
