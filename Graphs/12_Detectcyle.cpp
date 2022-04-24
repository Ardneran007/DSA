#include<bits/stdc++.h> 
using namespace std; 
//unidrected graph
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//here we need to pass a parent
// O(V+E)
//imp corner case
//Here parent means the vertex through which we have come to this vertex
bool DFS_rec(vector<int> adj[],int current,bool visited[],int parent)
{
    visited[current]=true;

    for(int next :adj[current])
    {
        if(visited[next]==false)
        {
            if(DFS_rec(adj,next,visited,current)==true)//if someone beneath returns true we need to return true
            {
                return true;
            }
        }
        //this condition must be outide of !visited
        else if(next!=parent)//if any adjacent node other than the parent is previously visited then there is a loop
            {
                return true;    
            }
    }
    return false;
}

bool DFS(vector<int> adj[],int V)
{
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(DFS_rec(adj,i,visited,-1)==true)//passing parent for first node as -1
                return true;
        }
    }
    return false;
}

int main() 
{ 
    int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

    if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

    return 0; 
} 
