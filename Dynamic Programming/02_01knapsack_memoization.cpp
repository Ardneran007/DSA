#include<bits/stdc++.h>
using namespace std;
//constraints-n<=100  W<=1000
int t[101][1002];


int Knapsack(int wt[],int val[],int W,int n)
{
    if(n==0 || W==0)
    {
        return 0;
    }

    if(t[n][W]!=-1)//
    {
        return t[n][W];
    }

    if(wt[n-1]<=W)
    {
        return  t[n][W] = max(val[n-1] + Knapsack(wt,val,W-wt[n-1],n-1) , Knapsack(wt,val,W,n-1));//
    }

    else //(wt[n-1]>wt)
    {
        return  t[n][W] = Knapsack(wt,val,W,n-1);//
    }
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

    memset(t,-1,sizeof(t));//initialize all the values with -1
    
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