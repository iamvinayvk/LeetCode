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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* dummy=ans;
        int carry=0;
        while(l1!=NULL&&l2!=NULL){
            int val=(carry+l1->val+l2->val)%10;
            cout<<carry<<" :carry\n";
            carry=(carry+l1->val+l2->val)/10;
            cout<<"l1->val: "<<l1->val<<" "<<l2->val<<"\n";
            cout<<val<<" "<<carry<<"\n";
            ListNode* temp=new ListNode(val);
            ans->next=temp;
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;
            
        }
        while(l1!=NULL){
            int val=(carry+l1->val)%10;
            carry=(carry+l1->val)/10;
            ListNode* temp=new ListNode(val);
            ans->next=temp;
            ans=ans->next;
            l1=l1->next;
            
        }
        while(l2!=NULL){
            int val=(carry+l2->val)%10;
            carry=(carry+l2->val)/10;
            ListNode* temp=new ListNode(val);
            ans->next=temp;
            ans=ans->next;
            l2=l2->next;
            
        }
        if(carry){
            ListNode* temp=new ListNode(carry);
            ans->next=temp;
            ans=ans->next;
        }
        return dummy->next;
    }
};