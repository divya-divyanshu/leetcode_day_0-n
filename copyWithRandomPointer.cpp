/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
void insertInBtw(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* nNode = new Node(temp->val);
        nNode->next = temp->next;
        temp->next = nNode;
        temp = temp->next->next;
    }
}

void connectRandom(Node* head){
    Node* temp = head;
    while(temp  != nullptr){
        if(temp->random == nullptr) temp->next->random = nullptr;
        else{
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
}

Node* connectNextExtractList(Node* head){
    Node* temp = head;
    Node* dnode = new Node(-1);
    Node* res = dnode;
    while(temp != nullptr){
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dnode->next;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        insertInBtw  (head);
        connectRandom (head);
        return connectNextExtractList(head);
    }
};