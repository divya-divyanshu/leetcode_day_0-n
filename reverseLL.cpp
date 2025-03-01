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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* temp = head;
        while (temp != nullptr){
            // stroing the front
            ListNode* front = temp->next;
            // linking temp to prev one -- reversing the link
            temp->next = prev;
            // making the temp as prev
            prev = temp;
            // moving to next node
            temp = front;
        }
        // at last prev will be pointing the last node, and temp will be pointin to null
        return prev;
    }
};