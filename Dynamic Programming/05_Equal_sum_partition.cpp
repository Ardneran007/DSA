#include<bits/stdc++.h>
using namespace std;
//constraints-n<=100  W<=1000

bool subset_sum(int A[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0)
            {
                t[i][j]=false;
            }
            if(j==0)
            {
                t[i][j]=true;
            }
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
bool equal_sum_partition(int A[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
    }
    if(sum%2!=0)
        return false;
    else
        return subset_sum(A,sum/2,n);
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    if(equal_sum_partition(A,n)==true)
        cout<<"Possible";
    else
        cout<<"Not possible";
    
    return 0;
}
/*
4
1 5 11 5


*/