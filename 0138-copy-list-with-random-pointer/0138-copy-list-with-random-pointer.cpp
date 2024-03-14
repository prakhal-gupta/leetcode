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
        // unordered_map<Node*, Node*> cpy;
        // Node* ptr = head;
        // while(ptr) {
        //     cpy[ptr] = new Node(ptr->val);
        //     ptr = ptr->next;
        // }
        // ptr = head;
        // while(ptr) {
        //     cpy[ptr]->next = cpy[ptr->next];
        //     cpy[ptr]->random = cpy[ptr->random];
        //     ptr = ptr->next;
        // }
        // return cpy[head];
        
        Node* ptr = head;
        while (ptr) {
            Node* temp = ptr->next;
            ptr->next = new Node(ptr->val);
            ptr->next->next = temp;
            ptr = temp;
        }
        ptr = head;
        while (ptr) {
            if (ptr->random)
                ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }
        ptr = head;
        Node* newHead = ptr->next;
        Node* newPtr = newHead;
        while (ptr) {
            ptr->next = newPtr->next;
            ptr = ptr->next;
            if (ptr) {
                newPtr->next = ptr->next;
                newPtr = newPtr->next;
            }
        }

        return newHead;
    }
};