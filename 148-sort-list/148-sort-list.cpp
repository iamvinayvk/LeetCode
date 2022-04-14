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
     ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = NULL;
        
        while(fast and fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        temp->next=NULL;
        // temp = slow;
        // slow->next = NULL;
        // cout<<"before: "<<head->val<<"\n";
        // ListNode* mid=getMid(head);
        // cout<<"before1: "<<head->val<<"\n";
        // ListNode* list1 = sortList(head);
        // cout<<"before2: "<<head->val<<"\n";
        // ListNode* list2 = sortList(mid);
        // slow->next = NULL;
        // slow->next = NULL;
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(slow);
        
        
        return mergeList(list1, list2);
    }
    
    ListNode* mergeList(ListNode* list1, ListNode* list2){
        ListNode* temp = new ListNode(0);
        ListNode* cur = temp;
        
        while(list1 and list2){
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            }
            else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        
        if(list1){
            cur->next = list1;
            // list1 = list1->next;
        }
        else{
            cur->next = list2;
            // list2 = list2->next;
        }
        
        return temp->next;
    }
};