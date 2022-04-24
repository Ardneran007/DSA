#include<bits/stdc++.h>
using namespace std;
//to delete search the key first
//in deleting we need to ensure that BST properties are maintained
// to delete a node from a Binary Search There are three posibilities:
// 1.Node to be deleted is a leaf node. //EASy
// 2.Node to be deleted has only one child. //EASY
// 3.Node to be deleted has two children.   //here we need to replace it with closest smaller or closest greatre value

//here i have replaced with closest greatest 

// inorder successor(Next node that comes next in inorder traversal){Bcas inorder traversal of BST is always sorted}
// is the closest higher value
// and inorder predecessor(N) is the closest lower value.

//time->o(h)
//space->o(h)
struct Node
{
    int key;
    Node *left,*right;
    Node(int x)
    {
        key=x;
        left=right=NULL;
    }
};
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }

} 
//to calculate the CLOSEST GREATER VALUE ie LEFTMOST LEAF OF RIGHT CHILD
//this give successor only when right child is empty
Node *getsuccessor(Node *curr)
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
Node *delNode(Node *root,int x)
{
    if(root==NULL)
        return root;
    if(root->key > x)
    {
        root->left=delNode(root->left,x);
    }
    else if(root->key < x)
    {
        root->right=delNode(root->right,x);
    }//uptill now code was like searching

    else//here we have found the Node to be deleted
    {
        if(root->left==NULL)//if it has only 1 child (also handles when both child are empty)
        {
            Node *temp=root->right;//we return this right child as a subtree
            delete(root);
            return temp;//this is do linking
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }
        //NOW WHEN BOTH CHILDREN ARE NON EMPTY
        //NOW HERE WE NEED TO FIND INORDER SUCCESSOR(CLOSEST GREATER VALUE)
        //importantobservation---->>>>>CLOSEST GREATER VALUE IS LEFTMOST LEAF OF RIGHT CHILD
        else
        {
            Node *succ=getsuccessor(root);
            root->key=succ->key;//copy 
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;

}

int main()
{
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(12);
	root->right->right=new Node(18);
	int x=15;
	inorder(root);
    cout<<endl;
	root=delNode(root,x);
	inorder(root);
    
    return 0;
}