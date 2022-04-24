#include<bits/stdc++.h>
using namespace std;
//Time complexity->o(h+n) h can be ignored
//auxiliary space->theta(w)

//CONCEPT->When u travel last Node of a level the next level is completely in the queue
//so, when we travel a current level completely we push NULL marker into the queue
//and when u see NULL next time u are sure ur complete next level is there in the queue so then u can push another NULL 

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

void printLevellinebyline(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)//different condition bcause at the end we have one node(NULL) in queue
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<"\n";
            q.push(NULL);
        }
        else
        {
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
    printLevellinebyline(root);
    return 0;
}
/*
              10
        20          30
      40  50          70
                         80  
                         */
                        
