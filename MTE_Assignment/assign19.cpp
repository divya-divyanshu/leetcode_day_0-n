class Solution {
public:
    bool isPalindrome(string s) {

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int k = 0;

        for(int i = 0 ; i < s.size(); i++){

            if (isalnum(s[i])){
                s[k] = s[i];
                k++;
            }
    }

    s.resize(k);

    // string ns1 = ns;
    // reverse(ns.begin(), ns.end());

    // if (ns1 == ns)
    //     return true;
    // else
    //     return false;
        
    // }

    int start = 0;
    int end = s.size() -1;

    while (start <=  end){
        if (s[start] == s[end]){
        }
        else{
            return false;
        }

        start++;
        end--;
    }
    return true;
    }
};