#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

int f=0;
vector<char> result;


void dfs(int l[][27],int a,int n,int p,int q,int c,vector<char> &s)
{
	if (f==1)
		return;

	s.push_back(char(a+'A'-1));
	s.push_back(char(n+'a'-1));

	c++;
	if(c==p*q)
	{
		if (f==0)
			result=s;
		f=1;
		return;
	}


		if (a-2>0)
		{
			if (n-1>0)
			{
				if (l[a-2][n-1]==0)
				{
					l[a-2][n-1]=1;
					dfs(l,a-2,n-1,p,q,c,s);
					l[a-2][n-1]=0;
				}
					

			}

			if(n+1<=p)
			{
				if (l[a-2][n+1]==0)
				{
					l[a-2][n+1]=1;
					dfs(l,a-2,n+1,p,q,c,s);
					l[a-2][n+1]=0;

				}
					
			
			}
		}

		if (n-2>0 && a-1>0)
		{
			if (l[a-1][n-2]==0)
			{
				l[a-1][n-2]=1;
				dfs(l,a-1,n-2,p,q,c,s);
				l[a-1][n-2]=0;
			}
				

		}


		if(n+2<=p && a-1>0)
		{
	
			if (l[a-1][n+2]==0)
			{
			
				l[a-1][n+2]=1;
				dfs(l,a-1,n+2,p,q,c,s);
				l[a-1][n+2]=0;
			}
				

		}


		if (n-2>0 && a+1<=q)
		{
	
			if (l[a+1][n-2]==0)
			{
	
				l[a+1][n-2]=1;
				dfs(l,a+1,n-2,p,q,c,s);
				l[a+1][n-2]=0;
			}
				

		}

		if (a+1<=q && n+2<=p )
		{
			if (l[a+1][n+2]==0)
			{
				l[a+1][n+2]=1;
				dfs(l,a+1,n+2,p,q,c,s);
				l[a+1][n+2]=0;
			}
				
		}

		if (a+2<=q)
		{
			if (n-1>0)
			{
				if (l[a+2][n-1]==0)
				{
					l[a+2][n-1]=1;
					dfs(l,a+2,n-1,p,q,c,s);
					l[a+2][n-1]=0;


				}
			}


			if (n+1<=p)
			{
				if (l[a+2][n+1]==0)
				{
					l[a+2][n+1]=1;
					dfs(l,a+2,n+1,p,q,c,s);
					l[a+2][n+1]=0;
				}	
			}
		}
	s.pop_back();
	s.pop_back();




}



int main()
{
	int t;
	cin>>t;

	for (int k=0;k<t;k++)
	{
		int flag=0;
		int p,q;
		cin>>p>>q;
		cout<<"Scenario #"<<k+1<<":"<<endl;

		for(int i=1;i<=q;i++)
		{
			for (int j=1;j<=p && flag==0;j++)
			{
				int l[27][27]={{0}};
				int c=0;
				vector<char> s;
				l[i][j]=1;
				dfs(l,i,j,p,q,c,s);
				if (f==1 && flag==0)
				{
					for (int h=0;h<result.size();h++)
					{
						int d=result[h]-'a'+1;
						if (h%2!=0)
							cout<<d;
						else
							cout<<result[h];
					}
						
					cout<<endl;
					flag=1;
					break;
				}
			}
		}

		f=0;
		if (flag==0)
			cout<<"impossible"<<endl;

		cout<<endl;
	}
}






