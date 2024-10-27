class Solution {
public:
    string removeOuterParentheses(string s) {

        if (s.length() == 0) return "";

        vector<char> temp;
        stack<char> st;
        vector<char> ans;

        for(int i = 0; i < s.length(); i++){
            
            if (s[i] == '(') {
                if (st.size() > 0) temp.push_back('(');
                st.push('(');
            }
            else if (s[i] == ')'){
                st.pop();
                if (st.size() > 0) temp.push_back(')');
            }
            else{
                temp.push_back(s[i]);
            }
        }

        if (temp.size() != 0){
                for (int i = 0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
        }

        string anss(ans.begin(), ans.end());
        return anss;
        
    }
};