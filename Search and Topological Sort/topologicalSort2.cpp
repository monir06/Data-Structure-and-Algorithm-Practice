#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int cycle=0;
int u=0;

void dfs(vector<int> a[],int v,int visited[],vector<int> &l,int n)
{
	visited[v]=1;

	for (int i=0;i<a[v].size();i++)
	{
		if (visited[a[v][i]]==0)
		{
			dfs(a,a[v][i],visited,l,n);
		}
		if (visited[a[v][i]]==1)
		{
			cycle=1;
		}

	}
	visited[v]=2;
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
		int* temp=new int[n+1];
		int* in=new int[n+1];

		int flag=0;
		for (int i=0;i<n+1;i++)
		{
			visited[i]=0;
			temp[i]=0;
			in[i]=0;
		}
		


		int i=0;
		for (;i<m;i++)
		{
			cycle=0;
			char q,p,w;
			cin>>q>>p>>w;
			int x=int(q-'A')+1;
			int y=int(w-'A')+1;
			in[y]++;
			temp[x]=1;
			temp[y]=1;
			
			a[x].push_back(y);
			vector<int> l;


			for (int i=0;i<n+1;i++)
			{
				visited[i]=0;
			}
				
			int f=1;
			for (int i=1;i<=n;i++)
			{
				if (temp[i]==0)
					f=0;
			}

			
			for (int i=1;i<=n;i++)
			{
				if (visited[i]==0)
				{
					dfs(a,i,visited,l,n);
				}
			}
			int z=0;
			for (int i=l.size()-1;i>0;i--)
			{
				if (find(a[l[i]].begin(), a[l[i]].end(), l[i-1]) == a[l[i]].end())
				{
					z=1;
				}
				
			}

			if (cycle==1)
			{
				cout<<"Inconsistency found after "<<i+1<<" relations."<<endl;
				flag=1;
				cycle=0;
				u=0;
				break;
			}

			else if (u==0 && f==1 && z==0)
			{
				cout<<"Sorted sequence determined after "<<i+1<<" relations: ";
				cycle=0;
				flag=1;
				u=0;
				for (int j=l.size()-1;j>=0;j--)
				{
					cout<<char('A'+l[j]-1);

				}
				cout<<'.';
				cout<<endl;
				break;	
			}
	
		}
		i++;
		for (;i<m;i++)
		{
			char q,p,w;
			cin>>q>>p>>w;
		}
		if (flag==0)
		{
			cout<<"Sorted sequence cannot be determined."<<endl; 
		}
		u=0;
		cycle=0;
		cin>>n>>m;
	}

}