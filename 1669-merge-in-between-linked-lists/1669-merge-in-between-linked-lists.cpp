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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    vector<int> mergeArray;
    int index = 0;
    ListNode* current1 = list1;
    while (index < a) {
        mergeArray.push_back(current1->val);
        current1 = current1->next;
        index++;
    }
    ListNode* current2 = list2;
    while (current2 != nullptr) {
        mergeArray.push_back(current2->val);
        current2 = current2->next;
    }
    while (index < b + 1) {
        current1 = current1->next;
        index++;
    }
    while (current1 != nullptr) {
        mergeArray.push_back(current1->val);
        current1 = current1->next;
    }
    ListNode* resultList = nullptr;
    for (int i = mergeArray.size() - 1; i >= 0; i--) { 
        ListNode* newNode = new ListNode(mergeArray[i], resultList);
        resultList = newNode;
    }
    return resultList;
    }
};