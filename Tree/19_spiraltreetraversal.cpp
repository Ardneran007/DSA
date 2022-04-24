#include<bits/stdc++.h>
using namespace std;

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

//Method 1 using 1 stack 1 queue
//time->o(n)
//in this method we do some extra work ie when items are to be reversed they 1 go in queue come out and go in stack 
void printSpiral(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *> q;
    stack<int> s;//
    bool reverse=false;//at 1st pass we dont nedd to reverse
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(reverse)//whenever going to reverse add it to stack
                s.push(curr->key);
            else
                cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        if(reverse)//whenever reverse display it
        {
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
        cout<<endl;
    }
}
//METHOD 2(efficient) 2 stacks
/*
1.push root in stack s1
2.while any of 2 stacks is not empty
    a.while s1 is not empty
     1. take out a node and print it
     2. push children of taken out node in s2(from left to right manner)

    b.while s2 is not empty
     1. take out a node and print it
     2. push children of taken out node in s1 in reverse order(from right to left manner)
*/
void printSpiralOptimised(Node *root)
{
    if(root==NULL)
        return;
    stack<Node *>s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while (!s1.empty()) { 
            Node* temp = s1.top(); 
            s1.pop(); 
            cout << temp->key << " "; 

            if (temp->left) //while pushing in s2 we push from left to right
                s2.push(temp->left); 
            if (temp->right) 
                s2.push(temp->right); 
            
        } 
        
        while (!s2.empty()) { 
            Node* temp = s2.top(); 
            s2.pop(); 
            cout << temp->key << " "; 
            if (temp->right) //while pushing in s1 we push from right to left(reverse order so that we can get reverse of it)
                s1.push(temp->right); 
            if (temp->left) 
                s1.push(temp->left); 
            
        } 
    }
}
int main()
{
    Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	printSpiral(root);
    cout<<"\n";
    printSpiralOptimised(root);
	// cout<<isCsum(root);
    return 0;
}

                        
