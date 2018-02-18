//https://vjudge.net/contest/211037#problem/B#include <iostream>
using namespace std;
#include <queue>          
#include <vector>  
#include <cmath>   
#include <limits.h>
typedef long long ll;

ll previous[100005];
void pr(ll x)
{
	if (x==0)
		return;
	else
		pr(previous[x]);
	cout<<x<<" ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	long long n,m;
	cin>>n>>m;
	vector< pair<long long,long long> > a[100005];

	while(m--)
	{
		ll i,j,w;
		cin>>i>>j>>w;

		a[i].push_back(make_pair(w,j));
		a[j].push_back(make_pair(w,i));

	}

	int visited[100005]={0};
	long long distance[100005];
	

	for (int h=0;h<=100005;h++)
	{
		distance[h]=LLONG_MAX;
		previous[h]=-1;
	}
		

	typedef pair<long long, ll> pii;
	priority_queue< pii> pq;

	pq.push(make_pair(0,1));
	distance[1]=0;
	previous[1]=0;
	while (!pq.empty())
	{
		pii e=pq.top();
		pq.pop();
		long long j=e.second;

		if (visited[j]==0)
		{
			visited[j]=1;
			for (ll i=0;i<a[j].size();i++)
			{
				if (distance[a[j][i].second]>distance[j]+a[j][i].first && visited[a[j][i].second]==0) 
				{
					distance[a[j][i].second]=distance[j]+a[j][i].first;
					previous[a[j][i].second]=j;
					pq.push(make_pair(-distance[a[j][i].second],a[j][i].second));
				}
				
			}
		}

	}

	if (distance[n]==LLONG_MAX)
		cout<<-1<<endl;
	else
	{
		pr(n);
		cout<<endl;
	}
		



}