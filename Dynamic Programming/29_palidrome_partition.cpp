#include<bits/stdc++.h>
using namespace std;

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
    //i==j one element is palidrome
    if(i>=j)
        return 0;

    if(ispalidrome(s,i,j)==true)
        return 0;

    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp_ans=1 + solve(s,i,k) + solve(s,k+1,j) ;//extra cost to do partition is 1
        ans=min(ans,temp_ans);
    }

    return ans;
}

int main()
{
    int n;
    string s;
    cin>>s;
    n=s.size();
    cout<<"Minimum Partition to be done "<<solve(s,0,n-1);//calculate i and j intially by doing dry run

    return 0;
}
