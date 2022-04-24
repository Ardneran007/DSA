#include <bits/stdc++.h>
using namespace std;
//Augmentation   BST-> To modify the definition of tree
//here we count NOdes in leftsubtree
struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  int lcount;//augmentation done
  Node(int k){
      key=k;
      lcount=0;//augmentation done
      left=right=NULL;
  }
};
//Naive
//time->O(h+k);
void printKth_optimised(Node *root,int k,int count)
{
    
}
int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int k=3;
	int count=0;
	cout<<"Kth Smallest: ";
	printKth_optimised(root,k,count);
	
	return 0;
}