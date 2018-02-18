#include <iostream>
using namespace std;
#include <queue>          // std::priority_queue
#include <vector>  
#include <map>
#include <string>
#include <cmath>   
#include <limits.h>
#include <climits>   

typedef long long ll;


int main()
{

	int f;
	cin>>f;

	while (f--)
	{	
		bool flag=false;
		long long dis[501];
		for (int i=0;i<=500;i++)
		{

			dis[i]=LLONG_MAX;
		}

		int n,m,w;
		cin>>n>>m>>w;
		vector < pair< pair<int, int>,int > > edges;
		while(m--)
		{
			int a,b,t;
			cin>>a>>b>>t;
			edges.push_back(make_pair(make_pair(a,b),t));
			edges.push_back(make_pair(make_pair(b,a),t));

		}
		while(w--)
		{
			int a,b,t;
			cin>>a>>b>>t;
			edges.push_back(make_pair(make_pair(a,b),-t));

		}

		dis[1]=0;
		vector < pair< pair<int, int>,int > > ::iterator it;
		for (int i=1;i<n;i++)
		{

			for(it=edges.begin();it!=edges.end();it++)
			{
				
				ll f=(*it).second;
				int a=(*it).first.first;
				int b=(*it).first.second;
				if (dis[a]!=LLONG_MAX)
				{
					if (dis[b]>f+dis[a])
						dis[b]=f+dis[a];
				}

			}
		}

		for(it=edges.begin();it!=edges.end();it++)
		{
				ll f=(*it).second;
				int a=(*it).first.first;
				int b=(*it).first.second;
			if (dis[a]!=LLONG_MAX)
			{
				if (dis[b]>f+dis[a])
				{
					flag=true;
					break;
				}
			}

		}

		if (flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}

}