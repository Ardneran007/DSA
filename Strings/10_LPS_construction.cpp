#include<bits/stdc++.h>
using namespace std;
/*
Longest proper prefix which is also suffix at that point
*/
//O(n3)
int longPropeffsuff(string str,int n)
{
    for(int len =n-1;len>0 ;len--)
    {
        bool flag=true;
        for(int i=0;i<len;i++)
        {
            if(str[i]!=str[n-len+i])
                flag=false;
        }
        if(flag==true)  
            return len;
    }
    return 0;
}

void FILLLPS(string str,int lps[])
{
    for(int i=0;i<str.length();i++)
    {
        lps[i]=longPropeffsuff(str,i+1);
    }

}
//---------------------------------------------------------------
//O(n)
/*
IDEA
1.if str[i] and  str[len] matches 
  lps[i]=len + 1 , len++

2.else
   a.if len=0  lps[i]=0
   b.else
        len=lps[len-1]
    we now compare str[i] and str[len]

*/
void fillLPS(string str, int *lps){
    int n=str.length(),len=0;
    lps[0]=0;

    int i=1;
    while(i<n){
        if(str[i]==str[len])
        {len++;lps[i]=len;i++;}

        else
        {if(len==0){lps[i]=0;i++;}
            else{len=lps[len-1];}//recursively 
        }
    }
}
 
int main() 
{ 
    string txt = "abacabad";int lps[txt.length()];
    fillLPS(txt,lps);
    for(int i=0;i<txt.length();i++){
        cout<<lps[i]<<" ";
    }
    
    return 0; 
} 