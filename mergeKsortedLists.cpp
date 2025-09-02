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

class compare{
      public:
      bool operator()(ListNode* a, ListNode*b){
          return a->val > b->val;
      }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>hpi;

        int k = lists.size();
        for(int i  = 0; i < k; i++){
            if(lists[i] != nullptr) hpi.push(lists[i]);
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(hpi.size() > 0){
            ListNode* temp = hpi.top();
            hpi.pop();

            if(head == nullptr){
                head = tail = temp;
                if(temp->next) hpi.push(temp->next);
            }
            else{
                 tail->next = temp;
                 tail = tail->next;
                 if(temp->next) hpi.push(temp->next);
            }
        }
        return head;
    }
};