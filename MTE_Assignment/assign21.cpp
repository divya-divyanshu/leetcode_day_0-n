class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;

        for (string x:tokens){

            if (x == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res = a+b;
                s.push(res);
            }
            else if (x == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res = b-a;
                s.push(res);
            }
            else if (x == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res = a*b;
                s.push(res);
            }
            else if (x == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res = b/a;
                s.push(res);
            }
            else s.push(stoi(x));
        }

        return s.top();
        
    }
};