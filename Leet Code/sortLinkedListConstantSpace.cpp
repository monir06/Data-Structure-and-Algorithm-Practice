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

struct ListNode {
  int val;
 ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverse(ListNode* li)
{
	if(l1==NULL)
		return NULL;
	
	ListNode* current = li;
	ListNode* prev =NULL;
	ListNode* next;

	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}

	return prev;

}


ListNode* merge(ListNode* li,int l, int r, int mid)
{

	


}


ListNode* mergeSort(ListNode* li,int l,int r)
{
	if(l<r)
	{
		int mid= (r-l)/2;
		mergeSort(li,l,mid);
		mergeSort(li,mid+1,r);
		merge(li,l,r,mid);
	}
}


int main(){

	

}