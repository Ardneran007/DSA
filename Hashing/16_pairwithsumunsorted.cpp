#include<bits/stdc++.h>
using namespace std;

//time->O9n
// space->O(n)
//before inserting we need to check(imp)
bool pairWithSumX(int A[],int n,int X)
{
    //here if we insert all the elements first and then travese it will be wrong
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(X-A[i])!=s.end())
            return true;
        else
            s.insert(A[i]);
    }
    return false;
}
int main()
{
    int arr[] = {3, 8, 4, 7, 6, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X =7;
    
    cout << pairWithSumX(arr, n, X);
    return 0;

}
