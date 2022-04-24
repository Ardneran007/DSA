#include<bits/stdc++.h>
using namespace std;
//optimised
//time->theta(n)
//space->O(n)

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    unordered_map<int,int> m;//this will print in any order as hashing is used
    for(int i=0;i<n;i++)
    {
        m[A[i]]++;
    }
    for(auto it:m)
    {
        cout<<it.first<<" "<<it.second<<"\n";
    }
    return 0;

}
