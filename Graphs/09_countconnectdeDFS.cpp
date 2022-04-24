// DFS on disconnected graphs.
#include<bits/stdc++.h>
using namespace std;

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
    // cout<<current<<" ";
    for(int next_vertex : adj[current])
    {
        if(visited[next_vertex]==false)
        {
            DFSrec(adj,next_vertex,visited);
        }
    }
}
int DFS(vector<int> adj[],int V,int s)//here this function initializes all visited=false
{
    int count=0;
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    //This is for Disconnected Graph
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            DFSrec(adj,i,visited);
            count++;
        }
    }
    return count;
}
int main()
{
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);

    cout<<"Print Graph\n";
    printGraph(adj,V); 
	cout << "Number of Connected Graphs "<<DFS(adj,V,0)<< endl; 
    return 0;
}
