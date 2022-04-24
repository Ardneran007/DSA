#include<bits/stdc++.h>
using namespace std;
//constraints-n<=100  W<=1000

int Rod_cutting(int Price[],int n)
{
    int size=n;
    int t[size+1][n+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
        }
    }
    //here all lengths are allowed so 
    int length[size];
    for(int i=1;i<=size;i++)
    {
        length[i-1]=i;
    }

    
    for(int i=1;i<size+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(length[i-1] <=j)
            {
                t[i][j]=max(Price[i-1] + t[i][j-length[i-1]],t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[size][n];

}

int main()
{
    int n;
    cin>>n;
    int Price[n];
    for(int i=0;i<n;i++)
        cin>>Price[i];
    int ans=Rod_cutting(Price,n);
    cout<<ans;
    return 0;
}
/*

*/