/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode* temporary=head;
        while(temporary->next){
            len++;
            temporary=temporary->next;
        }
        int indexFromStart=len-n;
        temporary=head;
        for(int i=0;i<indexFromStart-1;i++)
        {
            temporary=temporary->next;
        }
        if(indexFromStart==0)
            return head->next!=NULL?head->next:NULL;
        if(n==1)
        {
            temporary->next=NULL;
            return head;
        }
        temporary->next=temporary->next->next;
        return head;
        
    }
};