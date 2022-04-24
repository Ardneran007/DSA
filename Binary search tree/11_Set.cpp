#include<bits/stdc++.h>
using namespace std;
//SETS->they are use to store data in sorted form
//it ignores duplicate value
//USES->
//1.sorted stream of data
//2.doubly ended priority queue
int main()
{
    set<int> s;
    //to store elemetns in decreasing order
    //use
    //set<int,greater<int>> s;
    s.insert(10);
    s.insert(9);
    s.insert(3);
    s.insert(11);
    s.insert(9);
    for(auto it=s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<" ";
    }
    // for(int x :s)
    // {
    //     cout<<x<<" ";
    // }
    //-----------------------------------------
    auto it1=s.find(10);
    if(it1==s.end())
        cout<<"NOT FOUND\n";
    else
        cout<<"FOUND\n";
    //------------------------------------------

    //loewrbound
    auto it3=s.lower_bound(4);
    if(it3!=s.end())
        cout<<"Lower bound-> "<<(*it3);
    else
        cout<<"given element is greater than largest element";
    //----------------------------------------------------

    //upper bound
    auto it5=s.upper_bound(3);
    if(it5!=s.end())
        cout<<"Upper bound-> "<<(*it5);
    else
        cout<<"given element is greater than largest element";
    //---------------------------------------------------
    auto it2=s.find(10);
    s.erase(it2);   
    //to erase a series o felements
    // s.erase(it2,s.end());//this erases all the elements after 7
    //-----------------------------------------------
}
/*
TIme complexity
sets use self balancing red black
insert find count lowerbound upperbound erase-->logn
erase(it)---->amortised O(1)
begin end rbegin rend cbegin cend size empty--->O(1)
*/
