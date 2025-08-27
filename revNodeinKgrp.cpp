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
ListNode* findk(ListNode* temp, int k){
    k-=1;
    while(temp != nullptr && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}
void rev(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;   // Store next
        current->next = prev;   // Reverse pointer
        prev = current;         // Move prev
        current = next;         // Move current
    }

    // return prev; // New head
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode;
        ListNode* preNode = nullptr;

        while(temp != nullptr){
            ListNode* kthNode = findk(temp, k);
            if(kthNode == nullptr){
                if(preNode) preNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = nullptr;
            rev(temp);

            if(temp == head){
                head = kthNode;
            }
            else{
                preNode->next = kthNode;
           
            }
                 preNode = temp;
                temp = nextNode;
        }
        return head;
    }
};