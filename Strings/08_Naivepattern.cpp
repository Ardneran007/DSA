#include<bits/stdc++.h>
using namespace std;
//Naive O((n-m+1)*m)
//sliding pattern
void patSearchinng(string &txt,string &pat){
    int m=pat.length();
    int n=txt.length();
    for(int i=0;i<=(n-m);i++){
        int j;
        for(j=0;j<m;j++)
        if(pat[j]!=txt[i+j])
        break;
        
        if(j==m)
        cout<<i<<" ";
    }
}
//some optimisation to naive for all distinct pattern 
//O(n)  overall linear
void patSearchinng(string &txt,string &pat){
    int m=pat.length();
    int n=txt.length();
    for(int i=0;i<=(n-m);){
        int j;
        for(j=0;j<m;j++){
            if(pat[j]!=txt[i+j])
            break;
        }
        if(j==m)
        cout<<i<<" ";

        if(j==0)//
            i++;
        else //
            i+=j;
    }
}
int main()
{
    string txt,pattern;
    cin>>txt>>pattern;
    patSearchinng(txt,pattern);
    return 0;
}