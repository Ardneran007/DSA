#include <bits/stdc++.h>
using namespace std;

//substr concept VIMP
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n=str1.length();
        string clk="";
        string anti="";
        clk+=(str1.substr(2)+str1.substr(0,2));
        anti+=(str1.substr(n-2,2) + str1.substr(0,n-2));
      
    if(clk==str2 || anti==str2)
        return true;
    else
        return false;
    }
};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends