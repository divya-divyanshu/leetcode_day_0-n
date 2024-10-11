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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = list1;
        if (cur2->val < cur1->val){
            cur1 = list2;
            cur2 = list1;
            head = list2;
        }

        while (cur1 != nullptr && cur2 != nullptr){
            if (cur2->val >= cur1->val && (cur1->next == nullptr || cur2->val < cur1->next->val)){
            ListNode* temp = cur1->next;
            ListNode* node = new ListNode(cur2->val);
            cur1->next = node;
            node->next = temp;
            cur1 = node;
            cur2 = cur2->next;
         }

            else cur1 = cur1->next;
        }

        if (cur2 != nullptr) {
            cur1->next = cur2;
        }

        return head;
        
    }
};