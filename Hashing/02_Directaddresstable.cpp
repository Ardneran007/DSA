#include <bits/stdc++.h>
using namespace std;
/*
Direct Address Table
handles in O(1) when small keys or small range 
Now How to implement search insert and Delete in O(1)
->create boolean array[1000] initialize all elemnets a 0
*/

//good eg is ASCII Table
//But Problems with this is 
//1. LArge numbers
//2. keys can be string ,floating point numbers,address etc
//so we need hashing concept
struct DAT{
    int table[1000]={0};
    
    void insert(int i){
        table[i]=1;
    }
    
    void del(int i){
        table[i]=0;
    }
    
    int search(int i){
        return table[i];
    }
};

int main()
{
    DAT dat;
    dat.insert(10);
    dat.insert(20);
    dat.insert(119);
    cout<<dat.search(10)<<endl;
    cout<<dat.search(20)<<endl;
    dat.del(119);
    cout<<dat.search(119)<<endl;
    
    return 0; 
}
