#include <bits/stdc++.h> 
using namespace std; 
#define V 4
/*
This is naive and simple implementation 
using matrix representation
time->O(V*V)
*/

//Here we can do this optimised by using priority queue
vector<int> djikstra(int graph[V][V], int source)
{
    vector<int> dist(V,INT_MAX);
    dist[source]=0;
    vector<bool> finalised(V,false);

    for(int count=0;count<V-1;count++)
    {
        int u=-1;

        for(int i=0;i<V;i++)
        {
            if(!finalised[i] && (u==-1 || dist[i]<dist[u]))
                u=i;
        }
        finalised[u]=true;

        for(int v=0;v<V;v++)
        {
            if(graph[u][v]!=0 && finalised[v]==false)
            {
                dist[v]=min(dist[v],dist[u] + graph[u][v]);
            }
        }
    }
    return dist;
}

int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: djikstra(graph,0)){
	    cout<<x<<" ";
	} 

	return 0; 
} 