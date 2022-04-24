// We are given a binary tree and a leaf node, we need to find time to burn the 
// Binary Tree if we burn the given leaf at 0-th second. 
//hint1->time is the distance b/w leaf and farthest node
//hint2->we can reach to the farthest node only through one of the ancestors
//ans=max(distance between the burnt leaf to ancestor + distance b/w ancestor to farthest NODE)
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int burnTime(Node *root, int leaf, int &dist){
    if(root==NULL)
        return 0;
}
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->left->left=new Node(60);
	root->left->left->left->left=new Node(70);
	int dist=-1;int leaf=50;
	burnTime(root,leaf,dist);
	cout<<res;
}