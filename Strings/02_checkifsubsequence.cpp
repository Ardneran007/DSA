#include<bits/stdc++.h>
using namespace std;

bool issubseq(string s1,string s2,int n,int m)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]==s2[j])
        {
            j++;
        }
    }
    return(j==m);
}
//recursion not suitable but for ractise
bool issubeqrec(string s1,string s2,int n,int m)
{
    if(m==0)//this must be first condition  
        return true;
    if(n==0)
        return false;
    if(s1[n-1]==s2[m-1])
        return issubeqrec(s1,s2,n-1,m-1);
    else
        return issubeqrec(s1,s2,n-1,m);
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<issubseq(s1,s2,s1.size(),s2.size());
    return 0;
}