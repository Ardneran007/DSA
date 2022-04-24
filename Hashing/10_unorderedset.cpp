#include<iostream>
#include<unordered_set>
using namespace std;

//unordered set uses hashing so there is no order
//here order is not maintain
int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    for(int x :s)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    //-----------------------------------------------------
    cout<<s.size()<<endl;
    // s.clear();
    // cout<<s.size();
    //--------------------------------------------------------
    //Find function
    if(s.find(15)==s.end())
    {
        cout<<"NOT FOUND\n";
    }
    else
        cout<<"Found\n";
    //---------------------------------------------------------
    //erase
    s.erase(15);
    //s.erase(s.begin(),s.end());//
    return 0;

}
//--------------------------------------------
//Internal working ->hashing
//search,insert,delete,find(),size,empty->O(1)
//applications->
// whenever we need to do search insert delete or its 
// subset then we use hashing