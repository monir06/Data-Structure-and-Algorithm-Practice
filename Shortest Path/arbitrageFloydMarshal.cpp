#include <iostream>
using namespace std;
#include <queue>          // std::priority_queue
#include <vector>  
#include <map>
#include <string>
#include <cmath>   
#include <limits.h>
typedef long long ll;
map <string,int> m;
bool flag=false;

int main()
{
	int n;
	cin>>n;
	int j=1;
	while(n!=0)
	{
		map <string,int> m;
		bool flag=false;

		
		string s;
		for (int i=0;i<n;i++)
		{

			cin>>s;
			m[s]=i;
		}

		int i;
		cin>>i;
		float dis[30][30];
		for(int i=0;i<30;i++)
		{
			for (int k=0;k<30;k++)
			{
				if (i==k)
					dis[i][k]=1.0;
				else
					dis[i][k]=0.0;
			}
		}


		while (i--)
		{
			string x,y;
			float f;
			cin>>x>>f>>y;
			dis[m[x]][m[y]]=f;

		}

		for (int k=0;k<n;k++)
		{
			for (int a=0;a<n;a++)
			{
				for (int b=0;b<n;b++)
				{
					dis[a][b]=max(dis[a][b],dis[a][k]*dis[k][b]);

				}

			}
		}

		for (int a=0;a<n;a++)
			if (dis[a][a]>1.0)
			{
				flag=true;
				break;
			}

		if (flag)
			cout<<"Case "<<j<<": "<<"Yes"<<endl;
		else
			cout<<"Case "<<j<<": "<<"No"<<endl;
		flag=false;

		j++;
		cin>>n;
	}
}