class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        ListNode* prev = nullptr;
        head = nxt;
        while (curr && nxt) {
            curr->next = nxt->next;
            nxt->next = curr;
            if (prev) prev->next = nxt; 
            prev = curr;
            curr = curr->next;
            nxt = curr ? curr->next : nullptr;
        }
        return head;
    }
};