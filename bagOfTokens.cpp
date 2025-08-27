class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size()-1;
        int score = 0;
        int maxi  = 0;
        
        //if (power < tokens[0]) return 0;

        while(l <= r){
            if (power  >= tokens[l]){
                power -= tokens[l];
                score++;
                maxi = max(maxi, score);
                l++;
            }
            else{
                if ( score > 0){
                    power += tokens[r];
                    score--;
                    r--;
                }
                else break;
            }
        }

        return maxi;
    }
};