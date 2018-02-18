//https://vjudge.net/contest/211037#problem/C
#include <iostream>
using namespace std;
#include <queue>          
#include <vector>  
#include <cmath>   
#include <limits.h>


int main()
{
	int n,start,b;
	cin>>n>>start>>b;
	int index=1;
	vector< pair<int,int> > a[101];
	while(n--)
	{
		int f=0;
		int i,j,w;
		cin>>i;
		while(i--)
		{
			w=1;
			if (f==0)
				w=0;
			f=1;
			cin>>j;
			a[index].push_back(make_pair(w,j));			
		}

		index++;

	}

	int visited[101]={0};
	int distance[101];
	for (int h=0;h<=100;h++)
		distance[h]=INT_MAX;

	typedef pair<int, int> pii;
	priority_queue< pii , vector<pii>, greater< pii > > pq;

	pq.push(make_pair(0,start));
	distance[start]=0;
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

	if (distance[b]==INT_MAX)
		cout<<-1<<endl;
	else
		cout<<distance[b]<<endl;
}