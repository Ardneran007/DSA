#include<bits/stdc++.h>
using namespace std;
//DFS-> FIrst go to an adjacent then recursively call DFS 
//for that adjacent and thn go to next adjacent and so on

//We can also use stack to replace recursion with stack
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//Time ->O(V + E) vimp analysis can check vdo
void printGraph(vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void DFSrec(vector<int> adj[],int current,bool visited[])
{
    visited[current]=true;
    cout<<current<<" ";
    for(int next_vertex : adj[current])
    {
        if(visited[next_vertex]==false)
        {
            DFSrec(adj,next_vertex,visited);
        }
    }
}
void DFS(vector<int> adj[],int V,int s)//here this function initializes all visited=false
{
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    DFSrec(adj,s,visited);
}
int main()
{

    int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);

    cout<<"Print Graph\n";
    printGraph(adj,V);
	cout << "Following is Depth First Traversal: "<< endl; 
	DFS(adj,V,0); 
    
    return 0;
}
