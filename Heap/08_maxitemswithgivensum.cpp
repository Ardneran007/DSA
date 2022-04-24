#include<iostream>
#include<queue>
using namespace std;

//method 1.sort and traverse nlogn

//methd 2.heap O(n){inserting in queue} + O(res*logn){removing item from heap is logn}
int main() 
{ 
    int n=5;
    int cost[n]={1,12,5,111,200};
    int sum=10;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    int res=0;
    for(int i=0;i<n;i++)
        pq.push(cost[i]);//inserting is O(n)
    
    for(int i=0;i<n;i++){
        if(pq.top()<=sum){
            sum-=pq.top();//modigyng the same array
            pq.pop();//taking out element is O(logn)
            res++;
        }else{
            break;
        }
    }
    cout<<res;
    return 0;
} 
