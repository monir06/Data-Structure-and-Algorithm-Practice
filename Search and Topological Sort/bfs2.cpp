#include <iostream>
using namespace std;
#include <vector>
#include <queue> 
#include <map> 
#include <string>        



int main()
{
	queue<pair<int,int> > q;
	int a,b,c;
	cin>>a>>b>>c;
	int m[101][101]={{0}};



	map < pair<int,int>, pair <pair<int,int>, string> > p;

	q.push(make_pair(0,0));
	p[make_pair(0,0)]=make_pair(make_pair(0,0),".");	
	q.push(make_pair(a,0));
	p[make_pair(a,0)]=make_pair(make_pair(0,0),"FILL(1)");
	q.push(make_pair(0,b));
	p[make_pair(0,b)]=make_pair(make_pair(0,0),"FILL(2)");

	int w=1;
	string result="";

	int flag=0;
	while (q.size()!=0)
	{

		pair<int,int> e=q.front();
		q.pop();
		m[e.first][e.second]=1;
		if (e.first==c || e.second==c)
		{	
			flag=1;

			pair<pair<int,int>, string> r=p[make_pair(e.first,e.second)];
			pair<int,int> s= r.first;
			string h=r.second;
			result=h+"\n"+result;
			while (s != make_pair(0,0))
			{
				w++;
				r=p[s];
				s= r.first;
				h=r.second;
				result=h+"\n"+result;


			}
			break;
		}

		if (e.first<a)
		{
			if (p.find(make_pair(a,e.second))==p.end())
			{
				q.push(make_pair(a,e.second));
				p[make_pair(a,e.second)]=make_pair(make_pair(e.first,e.second),"FILL(1)");				
			}

			if (e.second>0)
			{
				if ((a-e.first)>e.second && p.find(make_pair(e.first+e.second,0))==p.end())
				{
					q.push(make_pair(e.first+e.second,0));
					p[make_pair(e.first+e.second,0)]=make_pair(make_pair(e.first,e.second),"POUR(2,1)");	
				}
					
				else if ((a-e.first)<=e.second && p.find(make_pair(a,e.second-a+e.first))==p.end())
				{
					q.push(make_pair(a,e.second-a+e.first));
					p[make_pair(a,e.second-a+e.first)]=make_pair(make_pair(e.first,e.second),"POUR(2,1)");
				}
					
			}

		}
			
		if (e.second<b)
		{
			if (p.find(make_pair(e.first,b))==p.end())
			{
				q.push(make_pair(e.first,b));
				p[make_pair(e.first,b)]=make_pair(make_pair(e.first,e.second),"FILL(2)");

			}
			
			if(e.first>0 )
			{
				if ((b-e.second)>e.first && p.find(make_pair(0,e.first+e.second))==p.end())
				{
					q.push(make_pair(0,e.first+e.second));
					p[make_pair(0,e.first+e.second)]=make_pair(make_pair(e.first,e.second),"POUR(1,2)");

				}
					
				else if ((b-e.second)<=e.first && p.find(make_pair(e.first-b+e.second,b))==p.end())
				{
					q.push(make_pair(e.first-b+e.second,b));
					p[make_pair(e.first-b+e.second,b)]=make_pair(make_pair(e.first,e.second),"POUR(1,2)");

				}
					

			}
		}
			
		if (e.first>0  && p.find(make_pair(0,e.second))==p.end())
		{
			q.push(make_pair(0,e.second));
			p[make_pair(0,e.second)]=make_pair(make_pair(e.first,e.second),"DROP(1)");

		}
			
		if (e.second>0 && p.find(make_pair(e.first,0))==p.end())
		{
			q.push(make_pair(e.first,0));
			p[make_pair(e.first,0)]=make_pair(make_pair(e.first,e.second),"DROP(2)");		

		}
				


	}
	if (flag==1)
	{
		cout<<w<<endl;
		cout<<result;
	}
	else
		cout<<"impossible"<<endl;



}