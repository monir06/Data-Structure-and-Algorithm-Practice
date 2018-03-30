#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <iomanip>


bool ispallin(string& s,string& r,int i)
{
    return(s.substr(0,i+1)==r.substr(s.length()-i-1,i+1));
}


string shortestPalindrome(string s) {
    
    if(s=="")
        return s;
    string r=s;
    reverse(r.begin(),r.end());
    char a=s[0];
    
    
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]==a)
        {
            if (ispallin(s,r,i))
            {
                string ans="";
                for(int j=s.length()-1;j>=i+1;j--)
                {
                    ans=ans+s[j];
                }
                ans=ans+s;
                return ans;
            }
        }
    }
    
}

int main()
{
    string s="aacecaaa";
    cout<<shortestPalindrome(s);
}