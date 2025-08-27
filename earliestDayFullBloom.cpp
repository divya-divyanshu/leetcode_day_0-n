class Solution {
public:
    static bool comp(pair<int, int>a, pair<int, int> b){
        return a.second > b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> temp;
        for(int i = 0; i < plantTime.size(); i++){
            temp.push_back({plantTime[i], growTime[i]});
        }

        sort(temp.begin(), temp.end(), comp);
        int plant = 0;
        int total  = 0;

        for(int i = 0; i < temp.size(); i++){
            plant += temp[i].first;
            total = max(total, plant+temp[i].second);
        }

        return total;

    }
};