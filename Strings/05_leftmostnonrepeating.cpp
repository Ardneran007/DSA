#include<bits/stdc++.h>
using namespace std;

const int CHAR=256;
//Naive
int leftMostnonrepeating(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        bool flag=false;
        for(int j=0;j<s.size();j++)
        {
            if(i!=j && s[i]==s[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
            return i;
    }
    return -1;
}
//soln using 2 traversals and creating count array
int leftMostnonrepeating1(string &s)
{
    int count[CHAR]={0};
    for(int i=0;i<s.length();i++)
    {
        count[s[i]]++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(count[s[i]]==1)
            return i;
    }
    return -1;
}
// optimised soln using one traversal
int leftMostnonrepeating2(string &s)
{
    int FI[CHAR];//create first occurence array
    fill(FI,FI+CHAR,-1);//initialise it as -1
    for(int i=0;i,s.size();i++)
    {
        if(FI[s[i]]==-1)
            FI[s[i]]=i;
        else
            FI[s[i]]==-2;//means it appeared and repeated
    }
    int res=INT_MAX;
    //this is not a second traversal of string it is 
    for(int i=0;i<CHAR;i++)
    {
        if(FI[i]>=0)
            res=min(res,FI[i]);
        
        return(res==INT_MAX)?-1:res;
    }
}
int main()
{
    string s1;
    cin>>s1;
    int ans=leftMostnonrepeating(s1);
    cout<<ans;
    return 0;
}