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


bool flag=false;

void rec(vector<vector<char> >& board,int** arr,pair<int,int> p,string a,int k)
{
	if(flag)
		return;
	if(k==a.length())
	{
		flag=true;
		return ;
	}
	if(p.first-1>=0 && board[p.first-1][p.second]==a[k] && arr[p.first-1][p.second]==0)
	{
		arr[p.first-1][p.second]=1;
		rec(board,arr,make_pair(p.first-1,p.second),a,k+1);
		arr[p.first-1][p.second]=0;
	}

	if(p.second-1>=0 && board[p.first][p.second-1]==a[k] && arr[p.first][p.second-1]==0)
	{
		arr[p.first][p.second-1]=1;
		rec(board,arr,make_pair(p.first,p.second-1),a,k+1);
		arr[p.first][p.second-1]=0;
	}

	if(p.first+1<board.size() && board[p.first+1][p.second]==a[k] && arr[p.first+1][p.second]==0)
	{
		arr[p.first+1][p.second]=1;
		rec(board,arr,make_pair(p.first+1,p.second),a,k+1);
		arr[p.first+1][p.second]=0;
	}

	if(p.second+1<board[p.first].size() && board[p.first][p.second+1]==a[k] && arr[p.first][p.second+1]==0)
	{
		arr[p.first][p.second+1]=1;
		rec(board,arr,make_pair(p.first,p.second+1),a,k+1);
		arr[p.first][p.second+1]=0;
	}
}




vector<pair<int,int> > firstfind(vector<vector<char> >& board,char a)
    {
        vector<pair<int,int> > v;
        for(int i=0; i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==a)
                {
                    v.push_back(make_pair(i,j));
                }
            }
        }
        return v;
    }
    

    
 bool exist(vector<vector<char> >& board, string word) {
        

        vector<pair<int,int> > v;
        v=firstfind(board,word[0]);
        int** arr=new int*[board.size()];

        for(int i=0;i<board.size();i++)
        {
        	arr[i]=new int[board[i].size()];
        }
        for(int i=0;i<board.size();i++)
        {
        	for(int j=0;j<board[i].size();j++)
        		arr[i][j]=0;
        }

        for(int i=0;i<v.size();i++)
        {
        	arr[v[i].first][v[i].second]=1;
        	rec(board,arr,v[i],word,1);
        	if(flag)
        		return true;
        	flag=false;

	        for(int i=0;i<board.size();i++)
	        {
	        	for(int j=0;j<board[i].size();j++)
	        		arr[i][j]=0;
	        }
        }
        return false;
        
 }




 int main(){


 	vector<vector<char> > b;
 	vector<char> t;
 	t.push_back('A');
 	t.push_back('B');
 	t.push_back('C');
 	t.push_back('E');
 	b.push_back(t);
 	vector<char> t1;
 	t1.push_back('S');
 	t1.push_back('F');
 	t1.push_back('E');
 	t1.push_back('S');
 	b.push_back(t1);
 	vector<char> t2;
 	t2.push_back('A');
 	t2.push_back('D');
 	t2.push_back('E');
 	t2.push_back('E');
 	b.push_back(t2);
 	string s="ABCESEEEFS";
 	cout<<exist(b,s);

/*
 	[
  ['A','B','C','E'],
  ['S','F','E','S'],
  ['A','D','E','E']
]
*/
 }