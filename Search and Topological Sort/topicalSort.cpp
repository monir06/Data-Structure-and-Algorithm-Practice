#include <iostream>
using namespace std;
#include <vector>


void dfs(vector<int> a[],int v,int visited[],vector<int> &l)
{
	visited[v]=1;
	for (int i=0;i<a[v].size();i++)
	{
		if (visited[a[v][i]]==0)
		{
			dfs(a,a[v][i],visited,l);
		}

	}

	l.push_back(v);
}

int main()
{
	int n,m;
	cin>>n>>m;
	while (n!=0 || m!=0)
	{
		vector<int> a[101];
		int* visited=new int[n+1];
		for (int i=0;i<n+1;i++)
			visited[i]=0;
		vector<int> l;

		for (int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
		}

		for (int i=1;i<=n;i++)
		{
			if (visited[i]==0)
			{
				dfs(a,i,visited,l);
			}
		}

		for (int i=l.size()-1;i>=0;i--)
		{
			cout<<l[i];
			cout<<(i==0?'\n':' ');

		}			
	

		cin>>n>>m;


	}

}