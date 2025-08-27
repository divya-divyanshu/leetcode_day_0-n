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
        vector<int> temp;
        ListNode* cur = head;
        // int n = 0;

        while (cur != nullptr){
            temp.push_back(cur->val);
            // n++;
            cur = cur->next;
        }

        cur = head;
        int i = 0;

        reverse(temp.begin(), temp.end());
        
        while (cur != nullptr){
            cur->val = temp[i];
            i++;
            cur = cur->next;
        }

        return head;

        
    }
};