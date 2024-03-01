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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*curr=head;
        for(int i=0;i<k;i++){
            if(curr==nullptr) 
                return head;
            curr = curr->next;
        }
        ListNode *prev=nullptr,*cur=head;
        for(int i=0;i<k;i++){
            ListNode *temp = cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        head->next = reverseKGroup(cur,k);
        return prev;
    }
};