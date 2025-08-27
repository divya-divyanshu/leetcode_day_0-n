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
    ListNode* sortList(ListNode* head) {
        ListNode* cur = head;

        vector<int>ll;

        while (cur != nullptr){
            ll.push_back(cur->val);
            cur = cur->next;
        }
        int i = 0;
        cur = head;
        sort(ll.begin(), ll.end());
        while (cur != nullptr){
            cur->val = ll[i];
            cur = cur->next;
            i++;
        }
        return head;
    }
};