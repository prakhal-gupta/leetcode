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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* reversedList = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversedList;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next == nullptr)
            return true;
        ListNode *s=head;
        ListNode *f=head;
        
        while(f!=nullptr && f->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }
        ListNode *r = reverseList(s);
        ListNode *temp = head;
        while(r!=nullptr){
            if(temp->val!=r->val)
                return false;
            temp=temp->next;
            r=r->next;
        }
        return true;
    }
};