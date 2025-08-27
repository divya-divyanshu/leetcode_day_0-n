class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        if (x == 1){
            head = head->next;
            head->prev = nullptr;
            return head;
        }
        Node* temp = head;
        int cnt = 0;
        while (temp != nullptr){
            cnt++;
            if (cnt == x) break;
            temp = temp->next;
        }
        if (temp->next == nullptr){
            Node* back = temp->prev;
            temp->prev = nullptr;
            back->next = nullptr;
            return head;
        }
        
        Node* temp0 = temp->prev;
        Node* temp2 = temp->next;
        
        temp2->prev = temp0;
        temp0->next = temp2;
        temp->next = nullptr;
        temp->prev = nullptr;
        
        return head;
        
    }
};