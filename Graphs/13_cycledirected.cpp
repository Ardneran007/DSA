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
bool DFS_rec(vector<int> adj[],int current,bool visited[],bool current_recursionstack[])
{
    visited[current]=true;
    current_recursionstack[current]=true;
    for(int next :adj[current])
    {
        if(visited[next]==false && DFS_rec(adj,next,visited,current_recursionstack)==true)
        {
            return true;
        }
        else if(current_recursionstack[next]==true)
        {
            return true;
        }
    }
    current_recursionstack[current]=false;
    return false;
}

bool DFS(vector<int> adj[],int V)
{
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    bool current_recursionstack[V];
    for(int i=0;i<V;i++)
    {
        current_recursionstack[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if((DFS_rec(adj,i,visited,current_recursionstack))==true)//passing parent for first node as -1
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
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

    return 0; 
} 
