/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

int fn(Node* temp){
    if(temp == nullptr) return 1;

    int a = fn(temp->next);
    if( a == 0 ) return 0;
    temp->data = temp->data+a;
    if(temp->data > 9) {
        temp->data = 0;
        return 1;
    }
    return 0;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
 
  
     int a = fn(head);
 
     if(a == 1){
         Node* newNode = new Node(1);
         newNode->next = head;
         return newNode;
     }
     return head;
}
