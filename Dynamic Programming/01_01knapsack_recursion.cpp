#include<bits/stdc++.h>
using namespace std;

int Knapsack(int wt[],int val[],int W,int n)
{
    if(n==0 || W==0)
    {
        return 0;
    }

    if(wt[n-1]<=W)
    {
        return max(val[n-1] + Knapsack(wt,val,W-wt[n-1],n-1) , Knapsack(wt,val,W,n-1));
    }

    else //(wt[n-1]>wt)
    {
        return Knapsack(wt,val,W,n-1);
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
    int W;
    cin>>W;
    int ans=Knapsack(wt,val,W,n);
    cout<<"Ans->"<<ans;
    return 0;
}
