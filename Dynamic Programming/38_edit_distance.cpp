#include<bits/stdc++.h>
using namespace std;

int edit_distance(string s1,string s2,int m,int n)
{
    if(m==0)//if first string ios empty we need to insert n characters
        return n;
    if(n==0)//if second string is empty we need to delete all characters of 1st string
        return m;
    if(s1[m-1]==s2[n-1])
    {
        return edit_distance(s1,s2,m-1,n-1);
    }
    else
    {
        return 1 + min(edit_distance(s1,s2,m,n-1)/*insert*/,min(edit_distance(s1,s2,m-1,n)/*deletion*/,edit_distance(s1,s2,m-1,n-1)));/*replace*/
    }//add 1 because we do one operation after calculating min 
    
}
//dp
int edit_distance_dp(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];

    for(int j=0;j<n+1;j++)
        dp[0][j]=j;
    for(int i=0;i<m+1;i++)
        dp[i][0]=i;
    
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]= 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }

        }
    }
    return dp[m][n];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size();
    int n=s2.size();
    cout<<"Minimum operations to convert s1 to s2 is "<<edit_distance(s1,s2,m,n)<<endl;
    cout<<"Minimum operations to convert s1 to s2 is "<<edit_distance_dp(s1,s2,m,n)<<endl;
    return 0;
}