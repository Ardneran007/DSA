#include<bits/stdc++.h>
using namespace std;

//better n general and quadratic in worst case
/*
1.Like naive we slide the pattern over txt one by one
2.Compare hash value of pattern with current hash value of txt 
if these 2 values match then only we compare individual hcaracter
p->hsah value of pattern
t->hash value of txt
hash func -> sum the values of inidividual character

we use cincept of rolling hash-> where we compute the next hash using previous hash in constatnt hash

ti+1=ti + txt[i+m] - txt[i]

to avoid collision we can use the weighted sum as hsah function
ti+1 =d(ti - txt[i]pow(d,m-1)) + txt[i+m]



*/
int main()
{
    string txt,pattern;
    cin>>txt>>pattern;
    patSearchinng(txt,pattern);
    return 0;
}