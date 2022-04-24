#include<bits/stdc++.h>
using namespace std;
//bool isTrue ->hidden parameter
int solve(string s,int i,int j,bool isTrue)
{
    //Base condition
    if(i>j)
        return false;
    if(i==j)
    {
        if(isTrue==true)//if(s[i]=T return true else return false)
        {
            return (s[i]=='T');
        }
        else//isTrue=false (if s[i] is F return true else return false)
        {
            return (s[i]=='F');
        }
    }

    //---------------------------------------------------------------------------
    //k loop
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2)//k can take only operatores so moke 2 at a time
    {
        int lT=solve(s,i,k-1,true);//no of ways left is true
        int lF=solve(s,i,k-1,false);
        int rT=solve(s,k+1,j,true);
        int rF=solve(s,k+1,j,false);

        //checking for operators & | ^
        if(s[k]=='&')
        {
            if(isTrue==true)
            {
                ans+=(lT*rT);//both should be true
            }
            else
            {
                ans+=(lF*rF) + (lT*rF) + (lF*rT);//anything should be false
            }
        }
        else if(s[k]=='|')
        {
            if(isTrue==true)
            {
                ans+=(lT*rT) + (lT*rF) + (lF*rT);
            }
            else
            {
                ans+=(lF*rF);
            }
        }
        else if(s[k]=='^')
        {
            if(isTrue==true)
            {
                ans+=(lT*rF) + (lF*rT);
            }
            else
            {
                ans+=(lT*rT) + (lF*rF);
            }
        }
    }
    return ans;
}

int main()
{
    string s="T^F&T";
    int n=s.size();
    int ans=solve(s,0,n-1,true);//we have to find no of ways true so pass it true
    cout<<"No of ways to make evaluation true is "<<ans<<endl;
    
    return 0;
}
