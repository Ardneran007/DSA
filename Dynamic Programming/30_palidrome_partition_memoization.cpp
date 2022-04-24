#include<bits/stdc++.h>
using namespace std;
//size<=1000
int static t[1001][1001];//
//memoization method
//VIMP-> Pass through refrence for not to get time limit excedded 
//as orelse it will create a copy 
bool ispalidrome(string &s,int i,int j)
{
    if(i==j)//single elemt
        return true;
    if(i>j)//empty string
        return true;
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string &s,int i,int j)
{
    //i==j one element invalid
    if(i>=j)
        return 0;

    if(ispalidrome(s,i,j)==true)
        return 0;

    if(t[i][j]!=-1)//check 
        return t[i][j];    

    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp_ans=1 + solve(s,i,k) + solve(s,k+1,j) ;//extra cost to multiply last two matrices
        ans=min(ans,temp_ans);
    }
    return t[i][j]=ans;//
}

int main()
{
    int n;
    string s;
    cin>>s;
    n=s.size();
    memset(t,-1,sizeof(t));//
    //i and j are 0 and n-1 respectively    
    cout<<"Minimum Partition to be done "<<solve(s,0,n-1);//calculate i and j intially by doing dry run

    return 0;
}
