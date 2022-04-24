#include<iostream>
#include<unordered_map>
using namespace std;

//unordered map uses hashing so there is no order
//here order is not maintain
//use to store key value pairs
int main()
{
    unordered_map<string,int> m;
    m["NRR"]=20;
    m["phy"]=30;
    //----------------------------------------
    m.insert({"webdev",15});
    //----------------------------------------
    //o/p can be in any order
    for(auto x: m)
    {
        cout<<x.first<<" "<<x.second<<"\n";
    }
    //-----------------------------------------
    //find()
    if(m.find("webdev")!=m.end())
    {
        cout<<"found\n";
    }
    else
        cout<<"NOT FOUND\n";
    //--------------------------------------
    //another method for finding
    auto it=m.find("NRR");
    if(it!=m.end())
    {
        cout<<(it->second);
    }
    //--------------------------------------
    //iterating
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<(it->first)<<" "<<(it->second)<<"\n";
    }
    //------------------------------------------
    cout<<m.size()<<"\n";
    m.erase("NRR");
    cout<<m.size()<<"\n";
    return 0;

}
//--------------------------------------------
//Internal working ->hashing
//search,insert,delete,find(),size,empty,[],count(),find()->O(1)
//applications->
// whenever we need to do search insert delete or its 
// subset then we use hashing