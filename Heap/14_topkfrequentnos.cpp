#include<bits/stdc++.h>

using namespace std;

//here sorting based on frequency ie key is frequency 
//key can be frequency,difference,etc
void topkfrequent(int A[],int size,int k)
{
    priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int>> >pq;
    unordered_map<int,int> mp;
    for(int i=0;i<size;i++)
    {
        mp[A[i]]++;
    }
    for(auto x:mp)
    {
        pq.push({x.second,x.first});//imp 
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top().second<<" ";
        pq.pop();
    }
}
int main() 
{ 
    int arr[] = {1,1,1,1,3,2,2,4,4,4,4};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
    topkfrequent(arr,size,k);
    return 0;
} 
