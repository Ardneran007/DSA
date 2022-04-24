#include<bits/stdc++.h>
using namespace std;
//constraints-n<=100  W<=1000

int Knapsack(int wt[],int val[],int W,int n)
{
    int t[n+1][W+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][W];
}

int main()
{
    int n;
    cin>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    int W;
    cin>>W;
    int ans=Knapsack(wt,val,W,n);
    cout<<"Ans->"<<ans;
    return 0;
}
/*
4
1 3 4 5
1 4 5 7
7


*/