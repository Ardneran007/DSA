#include<bits/stdc++.h>
using namespace std;

static int t[11][55];//based on constraints


int solve(int e,int f)
{
    if(e==1 || f==1 || f==0)
        return f;
    
    if(t[e][f]!=-1)
        return t[e][f];

    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1 + max(solve(e-1,k-1),solve(e,f-k));
        mn=min(mn,temp);
    }
    return t[e][f]=mn;
}

int main()
{
    int e=2,f=10;
    memset(t,-1,sizeof(t));
    cout<<"Minimum Ways in worst case "<<solve(e,f);

    return 0;
}