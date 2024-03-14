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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
            if(list1 == NULL)
                return list2;
            if(list2 == NULL)
                return list1;
            if(list1->val <=list2->val){
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else{
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
        ListNode *x = lists[lists.size()-1];
        ListNode *y = lists[lists.size() - 2];
        lists.pop_back();
        lists.pop_back();
        lists.push_back(mergeTwoLists(x,y));
        return mergeKLists(lists);
    }
};