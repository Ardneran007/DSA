#include<bits/stdc++.h>
using namespace std;


int solve(int e,int f)
{
    if(e==1 || f==1 || f==0)
        return f;
    
    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1 + max(solve(e-1,k-1),solve(e,f-k));
        mn=min(mn,temp);
    }
    return mn;
}

int main()
{
    int e=2,f=10;
    cout<<"Minimum Ways in worst case "<<solve(e,f);

    return 0;
}