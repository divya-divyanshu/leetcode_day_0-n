class MyQueue {
public:

        stack<int> input;
        stack<int> output;

    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        peek();
        int topE = output.top();
        output.pop();
        return topE;
        
    }
    
    int peek() {

        if (output.empty()){
            while(!input.empty()){
                int e = input.top();
                input.pop();
                output.push(e);
            }
        }

        return output.top();
        
    }
    
    bool empty() {
        return (input.empty() && output.empty());
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */