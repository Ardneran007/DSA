#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<int> adj[],int V,int s,int distance[])
{
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    queue<int> q;

    visited[s]=true;
    q.push(s);

    while(!q.empty())
    {
        int current=q.front();
        q.pop();

        for(int next:adj[current])
        {
            if(visited[next]==false)
            {
                distance[next]=distance[current]+1;//
                visited[next]=true;//
                q.push(next);
            }
        }
    }
}


int main() 
{ 
	int V=4;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,0,2); 
	addEdge(adj,1,3);
    int distance[V];
    for(int i=0;i<V;i++)
    {
        distance[i]=INT_MAX;//
    }

    distance[0]=0;//
    BFS(adj,V,0,distance);//

    for(int i=0;i<V;i++)
    {
        cout<<distance[i]<<" ";//
    }

	return 0; 
} 
