//https://vjudge.net/contest/212260#problem/G
#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <stdio.h>
typedef long long ll;
vector<ll> a[2001];
int color[2001]={0};

bool checkOdd(int v)
{
	queue<int> q;
	q.push(v);
	color[v]=0;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=0;i<a[t].size();i++)
		{
			if (color[a[t][i]]==color[t])
			{
				return false;
			}
				
			else if (color[a[t][i]]==-1)
			{
				color[a[t][i]]=1-color[t];
				q.push(a[t][i]);

			}	

		}

	}

	return true;
}


int main()
{
	int t;
	cin>>t;


	for (int k=1;k<=t;k++)
	{
		bool flag=true;
		ll n,m;
		scanf ("%lld %lld", &n, &m);
		for (int i=0;i<2001;i++)
		{
			color[i]=-1;
			a[i].clear();
		}

		while(m--)
		{
			int x,y;
			scanf ("%d %d", &x, &y);

			a[x].push_back(y);
			a[y].push_back(x);
		}

		for (int i=1;i<=n && flag;i++)
		{
			if (color[i]==-1)
			{
				if (!checkOdd(i))
				{
					flag=false;
					break;
				}
			}
		}
		cout<<"Scenario #"<<k<<":"<<endl;
		if (flag)
		{
			cout<<"No suspicious bugs found!"<<endl;
		}
		else
			cout<<"Suspicious bugs found!"<<endl;

		cout<<endl;

	}
}