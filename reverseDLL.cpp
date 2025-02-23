class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (head->next == nullptr) return head;
        DLLNode* cur = head;
        DLLNode* last = nullptr;
        while (cur != nullptr){
            last = cur->prev;
            cur->prev = cur->next;
            cur->next = last;
            
            
            cur = cur->prev;// to to to next node
        }
        
        return last->prev;
        
    }
};