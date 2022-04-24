#include<bits/stdc++.h>
using namespace std;


bool subset_sum(int A[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(A[i-1] <= j)
            {
                t[i][j] = (t[i-1][j-A[i-1]]) || (t[i-1][j]);
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
    if(subset_sum(A,sum,n)==true)
        cout<<"Possible";
    else
        cout<<"Not possible";
    
    return 0;
}
/*
4
2 3 7 8 10
11


*/