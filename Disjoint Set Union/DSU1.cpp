//https://vjudge.net/contest/212260#problem/E
#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
typedef long long ll;
int link[1002];
int size[1002];
int repair[1002]={0};

struct v
{
	ll x;
	ll y;

};

int find(int x)
{
	while (x!=link[x])
		x=link[x];
	return x;
}

int same(int a,int b)
{
	return (find(a)==find(b));
}

void unite(int a, int b)
{
	a=find(a);
	b=find(b);

	if (size[a]<size[b])
	{
		int temp=b;
		b=a;
		a=temp;
	}

	size[a]+=size[b];
	link[b]=link[a];
		
}

int main()
{
	int n;
	ll d;

	cin>>n>>d;
	vector<v> vertex;
	vector<int> a[1002];

	for (int i = 1; i <= n; i++) link[i] = i;
	for (int i = 1; i <= n; i++) size[i] = 1;

	for (int i=1;i<=n;i++)
	{	

		ll x,y;
		cin>>x>>y;

		for (int j=1;j<=vertex.size();j++)
		{
			v t=vertex[j-1];
			double dis=sqrt((t.x-x)*(t.x-x)+(t.y-y)*(t.y-y));
			if (dis<=d)
			{
				a[i].push_back(j);
				a[j].push_back(i);
			}	
		}	
		v temp={x,y};
		vertex.push_back(temp);

	}


	char o;

	while (cin>>o)
	{
		if (o=='O')
		{
			int p;
			cin>>p;
			repair[p]=1;
			for (int i=0;i<a[p].size();i++)
			{
				if (!same(p,a[p][i]) && repair[a[p][i]]==1)
				{
					unite(p,a[p][i]);
				}
			}

		}

		else if(o=='S')
		{
			int p,q;
			cin>>p>>q;
			if (same(p,q) && repair[p]==1 && repair[q]==1)
				cout<<"SUCCESS"<<endl;
			else
				cout<<"FAIL"<<endl;

		}
	}
}