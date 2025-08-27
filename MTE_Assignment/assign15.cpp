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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right) return head;



        ListNode* beg= head;
        vector<int> temp;

        int cnt = 1;

      
        while(cnt < left){
            beg = beg->next;
            cnt++;
        }

        ListNode* cur = beg;

        while (cnt <= right){
            temp.push_back(cur->val);
            cur = cur->next;
            cnt++;
        }


        cur = beg;
        int i = temp.size()-1;

        while (i >=0){

            cur->val = temp[i];
            cur = cur->next;
            i--;

            }

        return head;


        
    }
};