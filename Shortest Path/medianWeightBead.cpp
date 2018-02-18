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
		int n,m;
		cin>>n>>m;
		int l[100][100];

		for (int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
				l[i][j]=0;
		}

		while(m--)
		{
			int a,b;
			cin>>a>>b;
			l[a][b]=1;

		}

		for (int k=1;k<=n;k++)
		{
			for (int a=1;a<=n;a++)
			{
				for (int b=1;b<=n;b++)
				{
					if (l[a][k] && l[k][b])
						l[a][b]=1;
				}

			}
		}
		int c=0;

		for (int a=1;a<=n;a++)
		{
			int t=0;
			for (int b=1;b<=n;b++)
			{
				t=t+l[a][b];
			}

			if (t>=(n+1)/2)
				c++;

		}
		for (int b=1;b<=n;b++)
		{
			int t=0;
			for (int a=1;a<=n;a++)
			{
				t=t+l[a][b];
			}

			if (t>=(n+1)/2)
				c++;

		}

		cout<<c<<endl;
		

	}
}