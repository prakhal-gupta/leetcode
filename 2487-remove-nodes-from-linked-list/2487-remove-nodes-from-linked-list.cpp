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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* current = head;
        while (current != nullptr) {
            stack.push(current);
            current = current->next;
        }
        current = stack.top();
        stack.pop();
        int maximum = current->val;
        ListNode* resultList = new ListNode(maximum);
        while (!stack.empty()) {
            current = stack.top();
            stack.pop();
            if (current->val < maximum) {
                continue;
            }
            else {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultList;
                resultList = newNode;
                maximum = current->val;
            }
        }
        return resultList;
    }
};