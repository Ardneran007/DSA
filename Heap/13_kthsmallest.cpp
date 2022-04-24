    #include<iostream>
#include<queue>
using namespace std;
int KthLargest(int A[], int n, int k) {
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<n;i++)
        {
            pq.push(A[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
    
void kthsmallest(int A[],int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(A[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    cout<<pq.top();
}
int minimumcosttomake1elem(int A[],int n)
{
    priority_queue<int,vector<int>,greater<int> >pq;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        pq.push(A[i]);
    }
    while(pq.size()>1)
    {
        int min1=pq.top();
        pq.pop();

        int min2=pq.top();
        pq.pop();
        ans+=min1+min2;
        pq.push(min1+min2);
    }
    return ans;
}
int main() 
{ 
    int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int k = 3;
    cout<<k<<"th smallest element ";
    kthsmallest(arr,size,k);
    cout<<"Minimum cost to make 1 element in array is "<<minimumcosttomake1elem(arr,size);
    return 0;
} 
