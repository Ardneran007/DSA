#include<bits/stdc++.h>
using namespace std;
//serialization->given a binary tree convert it into string or an array
//reverse deserialization
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
const int EMPTY=-1;//here we are storing -1 when we encounter NULL 
//assumption->tree must not contain -1 as NODE
//here we can use any traversal here i used preorder
//time->theta(n) space=theta(n)
void serialize(Node *root,vector<int> &arr)
{
    if(root==NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left,arr);
    serialize(root->right,arr);
}
//time-theta(n)
Node *deserilaize(vector<int> &arr,int &index)//here passing index by refrence is important
{
    if(index==arr.size())//this means we have processed all the elements
        return NULL;
    int value=arr[index];
    index++;//important to increment here
    if(value==EMPTY)
    {
        return NULL;
    }
    Node *root=new Node(value);
    root->left=deserilaize(arr,index);//here we are following preorder so 
    root->right=deserilaize(arr,index);
    
    return root;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
} 

int main()
{
   	Node *root=new Node(10);
	root->left=new Node(20);
	
	vector<int> arr;
	serialize(root,arr);
	for (int x : arr) {
	    cout<<x<<" ";
	}
    cout<<"\n";
    int index=0;
    Node *root_new=deserilaize(arr,index);
    inorder(root_new);
    return 0;
}

                        
