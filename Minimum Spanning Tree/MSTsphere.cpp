//https://vjudge.net/contest/212260#problem/B
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
int link[101];
int size[101];

struct e
{
	int a;
	int b;
	double w;

};

struct sphere
{
	double x;
	double y;
	double z;
	double r;
};
bool compare(const e& a , const e& b) {
	return (a.w<b.w);
}
 
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

	while (cin>>n && n!=0)
	{
		vector<sphere> s;
		vector<e> edges;
		for (int i=1;i<=n;i++)
		{
			double x,y,z,r;
			cin>>x>>y>>z>>r;

			for (int j=1;j<=s.size();j++)
			{
				sphere t=s[j-1];
				double dis=sqrt((t.x-x)*(t.x-x)+(t.y-y)*(t.y-y)+(t.z-z)*(t.z-z));
				if (dis>t.r+r)
				{
					e newedge={j,i,dis-t.r-r};
					edges.push_back(newedge);
					
				}
					
				else
				{
					e newedge={j,i,0};
					edges.push_back(newedge);

				}
					
				
			}

			sphere temp={x,y,z,r};
			s.push_back(temp);

		}

		sort(edges.begin(),edges.end(),compare);
		for (int i = 1; i <= n; i++) link[i] = i;
		for (int i = 1; i <= n; i++) size[i] = 1;

		int c=0;
		double totalweight=0.0;
		while (!edges.empty() && c<n)
		{
			e t= edges.front();
			edges.erase(edges.begin());

			if (!same(t.a,t.b))
			{
				totalweight+=t.w;
				unite(t.a,t.b);
				c++;
			}
		}
		cout.setf(ios::fixed,ios::floatfield);
    	cout.precision(3);
		cout<<totalweight<<endl;

	}
}