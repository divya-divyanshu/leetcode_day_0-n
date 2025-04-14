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
    ListNode* findNth(ListNode* temp, int k){
        int cnt = 1;
        while(temp != nullptr){
            if(cnt == k) return temp;

            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next != nullptr){
            len++;
            tail =  tail->next;
        }

        if(k % len == 0) return head;
        k = k%len;

        tail->next = head;
        ListNode* newTail = findNth(head, len-k);
        head = newTail->next;
        newTail->next = nullptr;
        return head;
    }
};