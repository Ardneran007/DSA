#include<bits/stdc++.h> 
using namespace std; 
/*
ALGO;
1.Relax all vertices for V-1 times
2.Atlast we will get shortest distance

time->O((v-1)*E)


ADvantage
1.Can be used for negative weights
2********
IMP->
this algo can detect if there are negative cycles*
after V-1 relaxation if we get that in Vth relaxation the distance changes ie there is a negative 
cycle
*/
struct node{
    int u,v,wt;
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }    

};

int main()
{
    //Direcred graph input
    int n,m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    int source;
    cout<<"Enter source\n";
    //-----------------------------------------------------
    cin>>source;
    vector<int> distance(n,INT_MAX);
    distance[source]=0;

    for(int count=0;count<n-1;count++)
    {
        for(auto it: edges)
        {
            if(distance[it.v] > distance[it.u] + it.wt)
            {
                distance[it.v] = distance[it.u] + it.wt;
            }
        }
    }
    //-------------------------------------------------------
    //Negative cycle detection
    int found=0;
    for(auto it:edges)
    {
        if(distance[it.v] > distance[it.u] + it.wt)
        {
            cout<<"NEGATIVE CYCLE\n";
            found=1;
        }
    }
    //----------------------------------------------------------------
    //PRinting distance if negative cycles not found
    if(!found)
    {
        cout<<"Displaying Vertex distance from source\n";
        for(int i=0;i<n;i++)
        {
            cout<<i<<"  "<<distance[i]<<endl;
        }
    }
    return 0;
}
/*
ip

4 5
0 1 1
0 2 4
1 2 -3
1 3 2
2 3 3

0


*/