#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>

int main(){

	int l[]={5,10,-5};
	vector<int> asteroids(l,l+3);

	int* arr=new int[asteroids.size()];
	for(int i=0;i<asteroids.size();i++)
		arr[i]=1;


	for(int i=1;i<asteroids.size();i++)
	{
		if(asteroids[i]<0)
		{
			int j=i;
			j--;
			while(j>=0 && (asteroids[j]>0 || arr[j]==0))
			{

				if(arr[j]==0){}

				else if(asteroids[j]<(-asteroids[i]))
					arr[j]=0;
				else if(asteroids[j]==(-asteroids[i]))
				{
					arr[j]=0;
					arr[i]=0;
					break;
				}
				else
					break;
				j--;
				
			}
			if(asteroids[j]>0){
				arr[i]=0;
			}
		}

	}

	vector<int> v;

	for (int i=0;i<asteroids.size();i++)
	{

		if(arr[i]==1)
			v.push_back(asteroids[i]);
	}

}