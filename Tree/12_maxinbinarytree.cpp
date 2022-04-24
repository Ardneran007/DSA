//IMp check working and diagram
#include<bits/stdc++.h>
using namespace std;
//Time complexity-> O(n)
//auxiliary space->O(height) at any moment maximum activation recors->h+1
// Largest node(key) in a Tree is the maximum of the Tree.
//if the root is NULL return minus infinity

/*
Iterative solution->level order transversal of binary
 tree using queue data structure and initialize ans as minus infinite
 ans whatever item we pop out of the queue we compare with current result
 ansd update it 
 Tim ecomplexity->o(n)
 auxiliary space->o(width of tree)
 advantage->does not require recursion call overhead
 However which  method to use depends on binary tree
 if binary tree is squed then recursion is bad iteration good
 if tree is perfect ie there is 1 ode 2 node 4 node 8 node then recursion is good 
*/
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
//IMP->
//Here we compare 3 values root, maximuminleftsubtree ,maximuminrightsubtree and return maximum of all

int getmax(Node *root)
{
    if(root==NULL)
        return INT_MIN;//minus infinity
    else{
        //Here we compare 3 values root, maximuminleftsubtree ,maximuminrightsubtree and return maximum of all
        return max(root->key,max(getmax(root->left),getmax(root->right)));
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
    cout<<"max is "<<getmax(root);
    return 0;
}

                        
