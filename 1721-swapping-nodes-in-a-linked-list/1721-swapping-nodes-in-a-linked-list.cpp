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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        int val=0;
        ListNode* temp=head;
        while(temp){
            if(len==k-1)
            val=temp->val;
            temp=temp->next;
            len++;
        }
        int val2=0;
        int rt=0;
            temp=head;
        while(rt<=len-k){
            val2=temp->val;
            if(rt==len-k){
                temp->val=val;
            }
            temp=temp->next;
            rt++;
        }
        len=0;
        temp=head;
        while(len<k){
            if(len==k-1){
                temp->val=val2;
            }
            temp=temp->next;
            len++;
        }
        return head;
        
    }
};