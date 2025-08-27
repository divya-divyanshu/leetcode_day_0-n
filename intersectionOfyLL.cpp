/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* fn(ListNode* larger, ListNode* smaller, int d){
        while(d){
            d--;
            larger = larger->next;
        }
        while(larger != nullptr){
            if(larger == smaller) return larger;
            larger = larger->next;
            smaller = smaller->next;
        }
        return nullptr;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0;
        int n2 = 0;

        ListNode* temp = headA;
        while(temp != nullptr){
            n1++;
            temp = temp->next;
        }
        temp = headB;
        while(temp != nullptr){
            n2++;
            temp = temp->next;
        }

        if(n1 > n2) return fn(headA, headB, n1-n2);
        return fn(headB, headA, n2-n1);
    }
};