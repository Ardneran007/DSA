#include <bits/stdc++.h>
using namespace std;
//MIMP(very std quus and has many ds used in it)
/*
Q.Given a binary tree, we need to print nodes in all vertical lines starting from leftmost line to rightmost.
//for same vertical line use concept of horizontal distance
//if 2 nodes lie on the same vertical line the top NODE must be printed first
if two sam echildren lie on same vertical line then left children is given priority
*/

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
//

/*
1.crete a map
2.Do level order traversal and put Node in map
3.Traverse the map and print contents
*/
void vTraversal(Node *root){
    map<int,vector<int>> mp;//horizontal distance as keys and Nodes or Array of Node as a value
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        mp[hd].push_back(curr->key);//~
        q.pop();//MIMP CONDITION DON'T FORGET THIS
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    for(auto x:mp){
        for(int y:x.second)//VIMP nestong
            cout<<y<<" ";
        cout<<endl;
    }
}

int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    
    vTraversal(root);
          
    return 0;  
	
}