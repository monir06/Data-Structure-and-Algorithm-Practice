#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>

string multiply(string num1, string num2) {
    
   
    int n1=num1.length();
    int n2=num2.length();
    vector<int> v(n1+n2,0);

    for(int i=n1-1;i>=0;i--)
    {
    	int carry=0;
    	int j;
    	for(j=n2-1;j>=0;j--)
    	{
    		int a=num1[i]-'0';
    		int b=num2[j]-'0';
    		int p=carry+v[n2-j+n1-i-2]+a*b;
    		v[n2-j+n1-i-2]=p%10;
    		carry=p/10;
    	}
    	v[n2-j+n1-i-2]=carry;
    }
    string s;
    bool f=false;
    for(int i=v.size()-1;i>=0;i--)
    {
    	if(v[i]==0 && f==false){}
    	else{
    		s=s+to_string(v[i]);
    		f=true;

    	}
    }
    if(s=="")
    	s="0";

    return s;

}

int main()
{
	string s=multiply("123","456");

}