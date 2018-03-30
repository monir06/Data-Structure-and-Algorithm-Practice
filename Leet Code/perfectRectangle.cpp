#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>

bool isRectangleCover(vector<vector<int>>& rectangles){
	bool flag=false;
	int sum=0;
	int a=rectangles[0][0],b=rectangles[0][1],c=rectangles[0][2],d=rectangles[0][3];
	for(int i=0;i<rectangles.length;i++)
	{
		for(int j=i+1;j<rectangles.length;j++)
		{
			if ((rectangles[i][0]>rectangles[j][0] && rectangles[i][0]<rectangles[j][2]) || (rectangles[i][2]>rectangles[j][0] && rectangles[i][2]<rectangles[j][2]))
			{
				if ((rectangles[i][1]>rectangles[j][1] && rectangles[i][1]<rectangles[j][3]) || (rectangles[i][3]>rectangles[j][1] && rectangles[i][3]<rectangles[j][3]))
					flag=true;
			}


		}
		sum+=(rectangles[i][2]-rectangles[i][0])*(rectangles[i][3]-rectangles[i][1]);
		a=min(a,rectangles[i][0]);
		b=min(b,rectangles[i][1]);
		c=min(c,rectangles[i][2]);
		d=min(d,rectangles[i][3]);
	}

	if(flag || sum!=(c-a)*(d-b))
		return false;
	return true;
}

int main(){
	vector<vector<int>> rectangles;
	rectangles.push_back({1,1,3,3});
	rectangles.push_back({3,1,4,2});
	rectangles.push_back({1,3,2,4});
	rectangles.push_back({3,2,4,4});
	rectangles.push_back({2,3,3,4});
	bool f=isRectangleCover(rectangles);
	cout<<f<<endl;

}