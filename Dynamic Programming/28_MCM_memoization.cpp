#include<bits/stdc++.h>
using namespace std;
//size<=1000
int static t[1001][1001];//
//memoization method 
int solve(int A[],int i,int j)
{
    //i==j one element invalid
    if(i>=j)
        return 0;
    if(t[i][j]!=-1)//check 
        return t[i][j];    

    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp_ans=solve(A,i,k) + solve(A,k+1,j) + A[i-1]*A[k]*A[j];//extra cost to multiply last two matrices
        ans=min(ans,temp_ans);
    }

    return t[i][j]=ans;//
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    memset(t,-1,sizeof(t));//    
    cout<<"Minimum cost is "<<solve(A,1,n-1);//calculate i and j intially by doing dry run

    return 0;
}
