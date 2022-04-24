#include<bits/stdc++.h>
using namespace std;
//constraints-n<=100  W<=1000

int coin_change_mincoins(int Coins[],int n,int sum)
{
    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=0;
            if(i==0)
                t[i][j]=INT_MAX-1;
        }
    }

    //twist
    int j=1;
    for(int i=1;j<sum+1;j++)
    {
        if(j%Coins[0]==0)
        {
            t[i][j]=j/Coins[0];
        }
        else
        {
            t[i][j]=INT_MAX -1;
        }
    }

    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(Coins[i-1] <=j)
            {
                t[i][j]= min(t[i][j-Coins[i-1]] + 1 , t[i-1][j]) ;
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }

    if(t[n][sum]==INT_MAX-1)//VIMP
    {
        return -1;
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
    int ans=coin_change_mincoins(Coins,n,sum);
    cout<<ans;
    return 0;
}
/*

*/