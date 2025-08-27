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
    ListNode* middleNode(ListNode* head) {

        ListNode* cur;
        cur = head;
        int cnt = 1;
        while (cur->next != nullptr){
            cnt++;
            cur = cur->next;
        }
        int mid = cnt/2;

        ListNode* cur2 = head;

        while (mid>0){
            cur2 = cur2->next;
            mid--;
        }

        return cur2;
        
    }
};