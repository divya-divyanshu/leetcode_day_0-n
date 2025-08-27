class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* node = new StackNode(x);
        node->next = top;
        top = node;
        
    }

    int pop() {
        
        // code here
        if(top == nullptr) return -1;
        StackNode* temp = top;
        top = top->next;
        int val = temp->data;
        delete temp;
        return val;
    }

    MyStack() { top = NULL; }
};