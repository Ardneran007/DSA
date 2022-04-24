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
//constrruct a map and put the NOde and overwrite it so at last maps last Node will be in the map
void BottomView(Node *root){
    map<int,int> m;//here value is also int as we are goind to overwrite the NOde 
    queue<pair<Node *,int> >q;
    q.push({root,0});
    while(!q.empty())
    {
        auto p=q.front();
        Node *curr=p.first;
        int ht=p.second;
        m[ht]=(curr->key);//here we are overwriting the values of ht and at last it will contain last Node of the ht
        q.pop();//VIMP dont forget to pop
        if(curr->left!=NULL)
            q.push({curr->left,ht-1});
        if(curr->right!=NULL)
            q.push({curr->right,ht+1});
    }
    for(auto x:m)
    {
        cout<<x.second<<" ";
    }
}

int main() {
	
        	Node *root = new Node(10);  
            root->left = new Node(20);  
            root->right = new Node(30);  
            root->left->left = new Node(40);
            root->left->right = new Node(50);
            
            BottomView(root);
                  
    return 0;  
	
}