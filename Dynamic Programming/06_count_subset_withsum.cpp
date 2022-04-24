#include<bits/stdc++.h>
using namespace std;

int count_subset_sum(int A[],int sum,int n)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(A[i-1] <=j)
            {
                t[i][j]= t[i-1][j-A[i-1]] + t[i-1][j] ;
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    int sum;
    cin>>sum;
    cout<<"No of subsets with given sum is "<<count_subset_sum(A,sum,n);
    
    return 0;
}
/*
6
2 3 5 6 8 10
10
*/