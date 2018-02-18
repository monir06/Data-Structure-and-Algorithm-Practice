//https://vjudge.net/contest/211037#problem/A
#include <iostream>
using namespace std;
#include <queue>          
#include <vector>  
#include <cmath>   
#include <limits.h>


int main()
{
	int t,n;
	cin>>t>>n;
	vector< pair<int,int> > a[1001];
	while(t--)
	{
		int i,j,w;
		cin>>i>>j>>w;
		a[i].push_back(make_pair(w,j));
		a[j].push_back(make_pair(w,i));

	}

	int visited[1001]={0};
	int distance[1001];
	for (int h=0;h<=1000;h++)
		distance[h]=INT_MAX;

	typedef pair<int, int> pii;
	priority_queue< pii , vector<pii>, greater< pii > > pq;

	pq.push(make_pair(0,1));
	distance[1]=0;
	while (!pq.empty())
	{
		pii e=pq.top();
		pq.pop();
		int j=e.second;

		if (visited[j]==0)
		{
			visited[j]=1;
			for (int i=0;i<a[j].size();i++)
			{
				if (distance[a[j][i].second]>distance[j]+a[j][i].first && visited[a[j][i].second]==0) 
				{
					
					distance[a[j][i].second]=distance[j]+a[j][i].first;
					pq.push(make_pair(distance[a[j][i].second],a[j][i].second));
				}
				
			}
		}
	}
	cout<<distance[n]<<endl;
}