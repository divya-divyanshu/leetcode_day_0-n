/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        Node* temp = head;
        
        while (n > 0){
            if (temp->data == key) return true;
            temp = temp->next;
            n--;
        }
        return false;
    }
};