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
    
ListNode* help(vector<ListNode*> &lists, int l, int r ){
    if(l==r)
        return lists[l];
    if(l==r-1)
        return mergeTwoLists(lists[l], lists[r]);
    int mid = (l+r)/2;
    return mergeTwoLists(help(lists,l,mid), help(lists,mid+1,r));
}
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
        return help(lists,0,lists.size()-1);
    }
};