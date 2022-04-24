//MIMP
#include<bits/stdc++.h>
using namespace std;
int distance(int x,int y)
{
    return (x*x + y*y);
}
void kclosestpointstoorigin(vector<pair<int,int>> p,int n,int k)
{
    priority_queue<pair<int,pair<int,int>> > pq;
    for(int i=0;i<n;i++)
    {
        pq.push({distance(p[i].first,p[i].second),{p[i].first,p[i].second}});
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    while(pq.empty()==false)
    {
        pair<int,int> temp=pq.top().second;
        cout<<"("<<temp.first<<","<<temp.second<<")"<<" ";
        pq.pop();
    }
}

int main() 
{ 
    vector<pair<int,int>> p{{1,2},{2,2},{3,1},{2,-1},{5,-6},{0,-2}};
	int size =6;
	int k = 2;
    kclosestpointstoorigin(p,size,k);
    return 0;
} 
