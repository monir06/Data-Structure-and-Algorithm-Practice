#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>   
#include <map>
#include <cmath>
#include <math.h>




int arr[10001]={0};


void seive()
{

	for (int i=2;i<sqrt(10000);i++)
	{
		if (arr[i]==0)
		{
			for (int j=i*2;j<10000;j=j+i)
				arr[j]=1;
		}
	}
}

int main()
{
	seive();
	int t;
	cin>>t;
	for (int k=0;k<t;k++)
	{
		queue<int> q;
		vector<int> v;
		map<int,int> m;
		int a,b;
		cin>>a>>b;
		q.push(a);
		m[a]=0;
		int flag=0;
		while (q.size()!=0)
		{
			int y=q.front();
			q.pop();

			if (y==b)
			{
				cout<<m[y]<<endl;
				flag=1;
				break;
			}

			for (int i=1;i<=4;i++)
			{
				int z=y%int(pow(10,i));
				int x=y/int(pow(10,i));

				for (int j=0;j<=9;j++)
				{
					x=y/int(pow(10,i));
					x=(x*10+j)*int(pow(10,i-1))+(z%int(pow(10,i-1)));
					if (arr[x]==0 && (i!=4 || j!=0))
					{
						if (m.find(x)==m.end())
						{
							q.push(x);
							m[x]=m[y]+1;
						}
						

					}


				}
				
			}


		}

		if (flag==0)
			cout<<"Impossible"<<endl;

	}


}