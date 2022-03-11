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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* orignal=head;
        int si=0;
        while(orignal!=NULL){
            orignal=orignal->next;
            si++;
        }
        cout<<"si: "<<si<<" "<<k<<'\n';
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        // if(si<=k){
        //     cout<<"gaya\n";
        //     cout<<"head: "<<head->val<<"\n";
        //     return head;
        // }
        cout<<"gaya\n";
        ListNode* temp=head;
        k=k%si;
        while(k>0&&temp!=NULL&&temp->next!=NULL){
            ListNode* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            ListNode* last=temp->next;
            last->next=head;
            temp->next=NULL;
            head=last;
            k--;
        }
        if(k>0){
            return orignal;
        }
        return head;
    }
};