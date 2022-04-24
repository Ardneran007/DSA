#include<bits/stdc++.h>
using namespace std;
//constraints-n<=100  W<=1000

int coin_change_maxways(int Coins[],int n,int sum)
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
            if(Coins[i-1] <=j)
            {
                t[i][j]= t[i][j-Coins[i-1]] + t[i-1][j] ;
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
    int Coins[n];
    for(int i=0;i<n;i++)
        cin>>Coins[i];
    
    int sum;
    cin>>sum;
    int ans=coin_change_maxways(Coins,n,sum);
    cout<<ans;
    return 0;
}
/*

*/