#include<bits/stdc++.h>
using namespace std;
//optimised
//time->theta(n)
//space->O(n)
int countDist(int A[],int n)
{
    // unordered_set<int> s;
    // for(int i=0;i<n;i++)
    // {
    //     s.insert(A[i]);
    // }
    unordered_set<int> s(A,A+n);//this is shorter
    return s.size();
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<countDist(A,n);
    return 0;

}
