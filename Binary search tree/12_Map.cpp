#include<bits/stdc++.h>
using namespace std;
//chcek vdo

//MAPS->they are use to store data in sorted form
//it ignores duplicate value
//USES->
//1.sorted stream of data(key value pairs)
//2.doubly ended priority queue(key value pair)
int main()
{
    map<int,int> m;
    m.insert({100,200});
    m[5]=123;
    m.insert({3,100});
    m.insert({3,600});//this will be ignored
    //imp
    cout<<m[20]<<" \n";//if we access the item which is not present by square bracket then it is created and its value is initialise ot default value
 
    for(auto &x :m)
    {
        cout<<x.first<<" "<<x.second<<"\n";
    }
    
}
/*
TIme complexity
Maps use self balancing red black
insert find count lowerbound upperbound erase []-->logn
erase(it)---->amortised O(1)
begin end rbegin rend cbegin cend size empty--->O(1)
*/
