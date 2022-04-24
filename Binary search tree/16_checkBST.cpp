#include<bits/stdc++.h>
using namespace std;

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
//Naive inefficient
/*
TIME->O(n2)
for every Node 
1.Mind Max in left subtree
2.FInd Min in right subtree
3.if(max<root<min) then true
*/

//Correct tricky efficient
/*
1.Pass a range for every Node
2.For Root range is -infinte to +infinte
3.For Left child of Node in range,we change upper bounds to its Node value
4.For RIght value of a NOde in range we chaneg lower Bound as Node's value 
time->O(n)
*/
bool isBST(Node *root,int min,int max)//This is similar to inorder
{
    if(root==NULL)
        return true;
    return (root->key >min && root->key<max && isBST(root->left,min,root->key) && isBST(root->right,root->key,max));
}

//More optimised
/*
FACT-->A BINARY TREE IS BST only if ITS INORDER TRAVERSAL IS IN INCREASING ORDER
*/
int prevv=INT_MIN;
bool isBST_optimised(Node* root)  
{  
    if (root == NULL)  
        return true;  
    
    if(isBST_optimised(root->left)==false)return false;
    
    if(root->key<=prevv)return false;
    prevv=root->key;
    
    return isBST_optimised(root->right);
}
int main()
{
    Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBST(root,INT_MIN,INT_MAX))  
        cout<<"Is BST\n";  
    else
        cout<<"Not a BST\n";

    if(isBST_optimised(root))  
        cout<<"Is BST\n";  
    else
        cout<<"Not a BST\n";


    return 0;
}