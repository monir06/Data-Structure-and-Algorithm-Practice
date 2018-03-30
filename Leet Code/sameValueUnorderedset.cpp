#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <iomanip>

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(k==0 || nums.size()==0)
        return false;
    unordered_set<int> u;
    for(int i=0;i<=k && i<nums.size();i++)
    {
        u.insert(nums[i]);
    }

    if(k+1>nums.size())
    {
        if(u.size()<nums.size())
            return true;
    }
    else
    {	
        if(u.size()<k+1)
            return true;            
    }
    int a=nums.size()-k;
    
    for(int i=1;i<a;i++)
    {
        u.erase(nums[i-1]);
        u.insert(nums[i+k]);
        if(u.size()<k+1)
        	return true;
    }
    return false;
    
}

int main(){

	int l[]={1,2,3,4,5,6,7,8,9,10};
	vector<int> v(l,l+10);
	cout<<containsNearbyDuplicate(v,15);

}