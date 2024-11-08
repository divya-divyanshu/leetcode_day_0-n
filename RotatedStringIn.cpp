class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) return false;

        int n = s.length();

        string s2 = s+s;

        return s2.find(goal) != string::npos;
        // int k =0;
        // for (int i = 0; i <n ; i++){
        //     if (s[0] == goal[i]){
        //         k = i;
        //         break;
        //     }
        // }

        // for (int i = 0; i <n; i++){
        //     if (s[i] !=  goal[k%n]) return false;
        //     k++;
        // }

        // return true;
        
    }
};