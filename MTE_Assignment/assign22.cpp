class Solution {
public:
    bool queryString(string s, int n) {

        for (int i = 1; i <= n; i++){
                
                string temp = bitset<32>(i).to_string();
                temp = temp.substr(temp.find('1'));

                if (s.find(temp) == string::npos) return false;
                  
        }

        return true;
    }
};