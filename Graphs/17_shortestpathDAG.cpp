#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

/*
1.Initialize distance as INF
2.Distance source=0
3.Find topological sort
4.For every vertex u in topological Sort 
    a.For every adj v of u 
        if dis(v)>dis(u) + weight(u,v)
            dis(v)=dis(u) + weight(u,v)

*/

void Topological_sort(int node,bool visited[], stack<int> &s, vector<pair<int,int>> adj[])
{
    visited[node]=true;
    for(auto it:adj[node])//it={v,wt}
    {
        if(!visited[it.first])//it.first points to next vertex
        {
            Topological_sort(it.first,visited,s,adj);
        }
    }
    s.push(node);
}

void Shortest_Path(int source,int N,vector<pair<int,int>> adj[])
{
    stack<int> s;
    bool visited[N];
    for(int i=0;i<N;i++){
        visited[i]=false;
    }

    for(int i=0;i<N;i++)
    {
        if(!visited[i])
            Topological_sort(i,visited,s,adj);
    }

    int distance[N];
    for(int i=0;i<N;i++)
    {
        distance[i]=INF;
    }
    distance[source]=0;

    while(!s.empty())
    {
        int node=s.top();
        s.pop();

        if(distance[node]!=INF)
        {
            for(auto it:adj[node])
            {
                if(distance[it.first] > distance[node] + it.second)//relaxation
                {
                    distance[it.first] = distance[node] + it.second;
                }
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        (distance[i]==INF)? cout << "INF ": cout << distance[i] << " "; 
    }

}
int main() 
{ 
	int n, m;
    cout<<"Enter no of vertices and number of edges\n";
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	Shortest_Path(0, n, adj); 

	return 0; 
} 
/*
i/p
6 7
0 1 2
0 4 1
1 2 3
4 2 2
4 5 4
2 3 6
5 3 1
*/