/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        Node* nextNode = temp->next;
        while(nextNode != nullptr && nextNode->data == temp->data){
            Node* dup = nextNode;
            nextNode =  nextNode->next;
            delete dup;
        }
        temp->next = nextNode;

        if(nextNode) nextNode->prev = temp;

        temp = temp->next;
    }
    return head;
}
