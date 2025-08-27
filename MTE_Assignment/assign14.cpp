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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* cur = head;
        int cnt =0;
        while (cur != nullptr){
            cnt++;
            cur = cur->next;
        }

        cnt = cnt - n;

        if (cnt == 0) return head->next;

        cur = head;

        while (cnt > 1){
            cur = cur->next;
            cnt--;
        }

        cur->next = cur->next->next;

        return head;
        
    }
};