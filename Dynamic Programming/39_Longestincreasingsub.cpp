#include<bits/stdc++.h>
using namespace std;

/*
We will calculate LIS ending at current element 
Make a LIS ARRAY
LIS[0]=1

1.traverse every element before a current element and check if there is a 
smaller element  ..if yes then we check can we append it for LIS 
(by calculating max)
LIS[i]=max(LIS[i],LIS[j] + 1)//+1 for appending current elemt to LSI ending at j

2At last we return maxim element in LIS array

*/
//though this is not a good solun
int LIS_DP(int A[],int n)
{
    int LIS[n];
    LIS[0]=1;//0th elemtn 

    for(int i=1;i<n;i++)
    {
        LIS[i]=1;//assume lIS of every elemnt as 1(initialize it)
        for(int j=0;j<i;j++)
        {
            if(A[i] > A[j])//check for previous smaller element 
            {
                LIS[i]=max(LIS[i],LIS[j] + 1);//+1 for appending the current element
            }
        }
    }
    //we need to return maximum element
    int res=LIS[0];
    for(int i=1;i<n;i++)
    {
        res=max(res,LIS[i]);
    }

    return res;
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];

    cout<<"Longest increasing subsequence "<<LIS_DP(A,n)<<endl;
    return 0;
}