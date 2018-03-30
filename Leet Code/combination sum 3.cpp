#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <iomanip>


vector<vector<int> > gl;
void dfs(int str,int left,int count,vector<int> v)
{
    if(left<str)
    {
    	//cout<<"end"<<endl;
  		 return;
  		   	
    }
       
    if(count==1)
    {
        if(left<=9)
        {
            v.push_back(left);
            gl.push_back(v);
            for(int j=0;j<v.size();j++)
            	cout<<v[j]<<" ";
           // cout<<"pushed"<<endl;
        }
        return;
    }
    //cout<<str<<" "<<left<<" "<<count<<endl;
    v.push_back(str);
    if(count==2)
    	dfs(str+1,left-str,count-1,v);
    else
    {
	    for(int i=str+1;i<=9;i++){
	    	dfs(i,left-str,count-1,v);
	    }    	
    }

    
    
}
    
vector<vector<int> > combinationSum3(int k, int n) 
{
        
    for(int i=1;i<=9;i++)
    {
        vector<int> v;
        dfs(i,k,n,v);

    }
    
    return gl;
    
}



int main()
{
	vector<vector<int > > h;
	h=combinationSum3(9,3);
}
