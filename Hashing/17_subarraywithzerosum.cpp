#include<bits/stdc++.h>
using namespace std;
//?
//prefix sum + hashing
//time->O(n)
bool ZeroSumSubarray(int A[],int n)
{
    unordered_set<int> s;
    int pre_sum=0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=A[i];
        if(s.find(pre_sum)!=s.end())
        {
            return true;
        }
        if(pre_sum==0)
            return true;
        s.insert(pre_sum);
    }
    return false;
}
int main()
{
    int arr[] = {5, 3, 9, -4, -6, 7, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << ZeroSumSubarray(arr, n);
    return 0;

}
