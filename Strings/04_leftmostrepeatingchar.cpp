#include<bits/stdc++.h>
using namespace std;

const int CHAR=256;
//this needs 2 traversals
int leftMost(string &s)
{
    int count[CHAR]={0};
    for(int i=0;i<s.size();i++)
    {
        count[s[i]]++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(count[s[i]]>1)
            return i;
    }
    return -1;
}
int main()
{
    string s1;
    cin>>s1;
    int ans=leftMost(s1);
    cout<<ans;
    return 0;
}