class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        int n = arr.size();
        if ( n == 0)return nullptr;
        if ( n == 1) return new Node(arr[0]);
        
        Node* head = new Node(arr[0]);
        Node* back = head;
        Node* temp = head;
        for (int i = 1;i < n ; i++){
            Node* xnode = new Node(arr[i]);
            temp->next = xnode;
            xnode->prev = back;
            back = xnode;
            temp = temp->next;

        }
        return head;
    }
};