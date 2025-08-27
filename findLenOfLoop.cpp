/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int findlen(Node* slow){
    Node* fast = slow->next;
    int cnt = 1;
    while(slow != fast){
        fast = fast->next;
        cnt++;
    }
    return cnt;
}
int lengthOfLoop(Node *head) {
    // Write your code here
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return findlen(slow);
    }
    return 0;
}
