//https://vjudge.net/contest/212260#problem/F
#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <map>
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <stdio.h>
typedef long long ll;
int link[200001];
int size[200001];

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
	int t;
	cin>>t;

	while(t--)
	{
		ll n;
		scanf("%lld",&n);

		for (int i = 1; i <= 200001; i++) link[i] = i;
		for (int i = 1; i <= 200001; i++) size[i] = 1;

		map<string,int> m;
	
		int i=1;
		for(ll k=1;k<=n;k++)
		{
			string a,b;
			cin>>a>>b;
			if (m.count(a)==0)
			{
				m[a]=i;
				i++;
			}

			if (m.count(b)==0)
			{
				m[b]=i;
				i++;
			}
			if (!same(m[a],m[b]))
			{
				unite(m[a],m[b]);

			}
			cout<<size[find(m[a])]<<endl;
		}
	}
}