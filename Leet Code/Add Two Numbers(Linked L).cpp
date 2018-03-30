/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* makeList(ListNode* node,int i)
    {
        ListNode* temp=node;
        if(temp==NULL)
        {
            return new ListNode(i);
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new ListNode(i);
            return node;
        }

    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode * ans=NULL;
        while(l1!=NULL && l2!=NULL)
        {
            cout<<carry<<"yay"<<endl;
            int t=l1->val+l2->val+carry;
            cout<<"ff"<<endl;
            ans=makeList(ans,t%10);
            cout<<ans->val<<"vvvvvvvv"<<endl;
            cout<<"made"<<endl;
            carry=t/10;
            cout<<l1->val<<"l1val"<<endl;
            cout<<l2->val<<"l2val"<<endl;
            l1=l1->next;
            l2=l2->next;
            
        }
        if(l1==NULL)
        {
            cout<<"l1null"<<endl;
            while(l2!=NULL)
            {
                int t=l2->val+carry;
                ans=makeList(ans,t%10);
                cout<<ans->val<<"vvvvvvvv"<<endl;
                carry=t/10;
                l2=l2->next;
                
            }
        }
        else{
            cout<<"l2null"<<endl;
            while(l1!=NULL)
            {
                int t=l1->val+carry;
                cout<<t<<"tt"<<endl;
                ans=makeList(ans,t%10);
                cout<<ans->val<<"vvvvvvsssvv"<<endl;
                carry=t/10;
                l1=l1->next;
                
            }
        }
        
        if(carry>0)
            ans=makeList(ans,carry);
            
        //cout<<ans->next->val<<"jj"<<endl;
        return ans;
        
    }
};