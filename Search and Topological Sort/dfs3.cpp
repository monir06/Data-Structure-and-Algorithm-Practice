#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


void dfs(int m[][5],vector<int> &v,int s,int c,int a,int b)
{
	c++;
	s=s*10+m[a][b];

	if (c<6)
	{
		if (a+1<5)
			dfs(m,v,s,c,a+1,b);
		if (a-1>=0)
			dfs(m,v,s,c,a-1,b);
		if (b+1<5)
			dfs(m,v,s,c,a,b+1);
		if (b-1>=0)
			dfs(m,v,s,c,a,b-1);
	}

	else if (c==6)
	{
		if (find(v.begin(), v.end(), s) == v.end())
		{
			v.push_back(s);
		}

	}

}

int main()
{
	int m[5][5];
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			cin>>m[i][j];
		}
	}

	vector<int> v;
	
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			int s=0;

			int c=0;
			dfs(m,v,s,c,i,j);
		}
	}

	cout<<v.size()<<endl;
	

}