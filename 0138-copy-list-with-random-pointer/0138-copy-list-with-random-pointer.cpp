/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        unordered_map<Node*, Node*> cpy;
        Node* ptr = head;
        while (ptr) {
            cpy[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            cpy[ptr]->next = cpy[ptr->next];
            cpy[ptr]->random = cpy[ptr->random];
            ptr = ptr->next;
        }
        return cpy[head];
    }
};