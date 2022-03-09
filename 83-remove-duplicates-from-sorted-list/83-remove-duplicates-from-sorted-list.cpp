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
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode* prev=NULL;
        // ListNode* curr=head;
        // while(curr!=NULL&&curr->next!=NULL)
        // {
        //     if(curr->val==curr->next->val)
        //     {
        //         curr->next=curr->next->next;
        //     }
        //     else
        //     {
        //         curr=curr->next;
        //     }
        // }
        // return head;
        ListNode* temp=head;
        while(temp!=NULL&&temp->next!=NULL){
            while(temp!=NULL&&temp->next!=NULL&&temp->val==temp->next->val){
                temp->next=temp->next->next;
            }
            if(temp!=NULL&&temp->next!=NULL){
                temp=temp->next;           
            }
        }
        return head;
    }
};