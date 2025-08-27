class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* xnode = new Node(x);
        if (head == nullptr){
            head = xnode;
            return head;
        }
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = xnode;
        return head;
    }
};