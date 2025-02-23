class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        Node* xnode = new Node(data);
        pos = pos+1; // to make 1-based indexing
        if (head == nullptr) return xnode;
        Node* temp = head;
        int cnt = 0;
        while (temp != nullptr){
            cnt++;
            if (cnt == pos)
                break;
            
            else
                temp = temp->next;
        }
        
        if (temp->next == nullptr){
            temp->next = xnode;
            xnode->prev = temp;
        }
        
        else
        {   
            Node* front = temp->next;
            xnode->next = temp->next;
            temp->next = xnode;
            xnode->prev = temp;
            front->prev = xnode;
        }
        
        return head;
        
    }
};