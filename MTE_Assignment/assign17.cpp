class MyStack {
public:

    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i= 1; i< q.size(); i++){
            int e = q.front();
            q.pop();
            q.push(e);
        }
        
    }
    
    int pop() {
        int e = q.front();
        q.pop();
        return e;

    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {

        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */