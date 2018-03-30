#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <cmath>

int findComplement(int num) {
    int n=0;
    int ans=0;
    while(num)
    {
        ans+=(((num%2)+1)%2)*pow(2,n);
        cout<<ans<<endl;
        num=num/2;
        n++;
    }
    return ans;
    
}

int main(){
	cout<<findComplement(5);
	
}