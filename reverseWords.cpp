class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        string word;
        stack<string> st;

        while (ss >> word){
            st.push(word);
        }

        string res;

        while(!st.empty()){
            res += st.top();
            if (st.size() != 1) res += ' ';
            st.pop();
        }

       return res;
    }
};