#include<bits/stdc++.h>
using namespace std;
// Maximum Width of Binary tree is the maximum number of nodes present in a level of the Tree.
// Hint->use level order traversal line by line logic to find maximum width of the Binary Tree.
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
//Time ->o(n)
//space->o(maxwidth)
int maxWidth(Node *root)
{
    if(root==NULL)
        return 0;
    queue<Node *>q;
    q.push(root);
    int res=0;
    while(!q.empty())
    {
        int count=q.size();
        res=max(count,res);
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return res;
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
	// cout<<"Naive->"<<isBalanced(root)<<endl;
	// cout<<"Optimised->"<<isBalancedoptimised(root);
	cout<<maxWidth(root);
    return 0;
}

                        
