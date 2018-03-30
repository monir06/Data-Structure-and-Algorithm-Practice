#include <iostream>
using namespace std;
#include <queue>     
#include <stack>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>


int main(){

	int m[]={2,1,3,42,0,100,200,321,-1,-123,231312,-23};
	stack<int> s1;

	for(int i=0;i<12;i++)
		s1.push(m[i]);

	stack<int> s2;

	while(!s1.empty())
	{
		if(s2.empty())
		{
			int a=s1.top();
			s1.pop();
			s2.push(a);
		}
		else
		{
			int x=s1.top();
			s1.pop();
			if(s2.top()>x)
				s2.push(x);
			else
			{
				while(!s2.empty() && s2.top()<x)
				{
					int a=s2.top();
					s2.pop();
					s1.push(a);
				}
				s2.push(x);
			}
		}

	}

	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}

	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
		


}