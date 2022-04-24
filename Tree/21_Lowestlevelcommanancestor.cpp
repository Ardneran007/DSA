#include<bits/stdc++.h>
using namespace std;
//LOWEST (LEVEL) COMMON ANCESTORS    topmost height is highest  
//ancestor of a NOE is NOde itself its parent its its parent and so on
//LCA can also be used to find the distance b/w 2 nodes
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

int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=20,n2=50;
	
	Node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
    return 0;
}

                        
