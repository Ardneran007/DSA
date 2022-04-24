// /There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.
//MIMP
#include<bits/stdc++.h>
using namespace std;
//same quus JPMC

int connectropes(int A[],int n)
{
    int cost=0;
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=0;i<n;i++)
    {   
        pq.push(A[i]);
    }
    while(pq.size()>=2)
    {
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        cost+=first+second;
        pq.push(first+second);
    }
    return cost;
}

int main() 
{ 
    int arr[] = {1,2,3,4,5};
	int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Minimum Cost is ->"<<connectropes(arr,size);
    return 0;
} 
