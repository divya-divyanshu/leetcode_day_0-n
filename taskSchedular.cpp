class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        if (n == 0) return tasks.size();

        vector<int>mpp(26, 0);
        for(char&ch:tasks) mpp[ch - 'A']++;
        sort(begin(mpp), end(mpp));

        int maxi = mpp[25];
        int empty = maxi - 1;
        int idleSpots = n*empty;

        for(int i = 24; i >= 0; i--){
            idleSpots -= min(mpp[i], empty);
        }
        if(idleSpots > 0) return tasks.size()+idleSpots;
        return tasks.size();
    }
};