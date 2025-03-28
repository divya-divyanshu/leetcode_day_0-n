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
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;

        vector<int>ll;

        while (cur != nullptr){
            ll.push_back(cur->val);
            cur = cur->next;
        }
        int l =0;
        int r = ll.size() -1;
        while (l < r){
            if (ll[l] != ll[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};