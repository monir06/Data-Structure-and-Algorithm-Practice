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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* current=head;
        ListNode* next;
        ListNode* before;
        ListNode* after;
        
        for(int i=1;i<=n;i++)
        {
            next=current->next;
            
            if(i==m)
            {
                before=prev;
                after=current;
            }
            if(i==n)
            {
                after->next=next;
                before->next=current;
            }
            if(i>m)
            {
                current->next=prev;
            }
            
            prev=current;
            current=next;
            
        }

        return dummy.next;
        
    }
};