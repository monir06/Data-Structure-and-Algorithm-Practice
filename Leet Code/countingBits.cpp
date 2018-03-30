#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>

class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> v;
        v.push_back(0);
        for(int i=1;i<=num;i++)
        {
            v.push_back(v[i/2]+(i%2));
        }
        return v;
        
    }
};