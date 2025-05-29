class Solution {
public:
    bool isValid(string& temp){
        stack<char>st;
        for(int i  = 0; i < temp.size(); i++){
            if(temp[i] == '(') st.push('(');
            else if(temp[i] == ')'){
                if(st.empty()) return false;
                st.pop();
            }
        }    
        return st.empty();
    }
    void solve(int n, string& temp, vector<string>&ans){
        if(temp.size() == 2*n) {
            if(isValid(temp))
                ans.push_back(temp); 
            return;
        }
        //leftBrackt
        temp.push_back('(');
        solve(n, temp, ans);
        temp.pop_back();
        // right bracket
        temp.push_back(')');
        solve(n, temp, ans);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp = "";
        solve(n, temp, ans);
        return ans;
    }
};