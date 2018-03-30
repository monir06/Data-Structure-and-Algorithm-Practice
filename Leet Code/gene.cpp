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
int ct=-1;
void dfs(string& start,string& end,vector<string>& bank,int c,int* &visited)
{
    cout<<start<<"start"<<endl;
    if(flag)
        return;
    if(start==end)
    {
        cout<<end<<"end";
        ct=c;
        flag=true;
        return;
    }
    for(int i=0;i<bank.size();i++)
    {
        if(start==bank[i])
            visited[i]=1;
        int f=0;
        for(int a=0;a<start.length();a++)
        {
            if (start[a]!=bank[i][a])
                f++;
        }
        if(f==1 && visited[i]==0)
        {
            visited[i]=1;
            dfs(bank[i],end,bank,c+1,visited);
        }
    }
    
    
}

void minMutation(string start, string end, vector<string>& bank) {
    
    int* visited=new int[bank.size()];
    for(int i=0;i<bank.size();i++)
        visited[i]=0;
    dfs(start,end,bank,0,visited);
    
    
    

}
int main()
{
    string s[8]={"AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC"};
    vector<string> v(s,s+8);
    minMutation("AAAACCCC","CCCCCCCC",v);
    cout<<ct<<endl;
}



    

