#include<bits/stdc++.h>
#define ll long long 
#define lld long double
#define deb(x) cout << #x << " = " << x << endl
using namespace std;

int main() {
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size())
        cout<<"NO\n";
    else
    {
        string total=a+a;
        if(total.find(b)!=string::npos)//
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
    return 0;
}