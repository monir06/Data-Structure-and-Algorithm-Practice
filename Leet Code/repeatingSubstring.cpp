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

bool repeatedSubstringPattern(string s){
	for(int k=1;k<=(s.length())/2;k++)
	{
		
		int i=0;
		bool flag=true;
		int c=0;
		cout<<k<<" k";
		while(i<k && flag)
		{

			char a=s[i];
			cout<<a<<"aa";
			for(int j=i;j<s.length();j+=k)
			{
				if(s[j]==a)
				{
					cout<<j<<" ";
					c++;
				}
				else
					flag=false;


			}
			i++;	
			cout<<i<<" i";	
		}

		cout<<c<<" c"<<endl;
		if (c==s.length() && c%k==0)
			return true;

	}
	return false;

}



int main(){
	string s;
	s="aabaaba";
	cout<<repeatedSubstringPattern(s);

	
}