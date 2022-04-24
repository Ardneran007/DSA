#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,source;
    cin>>n>>m;
    vector<pair<int,int> > g[n];//0-indexed adjacency list for of graph

    int a,b,wt;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>wt;
        g[a].push_back({b,wt});
        g[b].push_back({a,wt});
    }
    cout<<"\nEnter source\n";
    cin>>source;
    //---------------------------------------------------------------------------------------------------------------------
    //Algo->
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
    vector<int> distTo(n,INT_MAX);

    distTo[source]=0;
    pq.push({0,source});//{dist,from}

    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();

        for(auto it: g[prev])
        {
            int next=it.first;
            int nextdist=it.second;//weight
            if(distTo[next] > dist +nextdist)//relax
            {
                distTo[next] = dist +nextdist;
                pq.push({distTo[next],next});
            }
        }
    }
    cout << "The distances from source, " << source << ", are : \n";
	    for(int i = 0 ; i<n ; i++)	cout << distTo[i] << " ";
	    cout << "\n";
}
/*
ip
4 5
0 1 50
0 2 100
1 2 30 
1 3 200
2 3 20

0



*/