class Twitter {
    unordered_map<int, unordered_map<int, int>> follows;   
    unordered_map<int, vector<pair<int,int>>> posts;       
    int timeStamp = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; 

        for (auto &p : posts[userId]) {
            pq.push(p);
        }

        for (auto &f : follows[userId]) {
            if (f.second == 1) {
                for (auto &p : posts[f.first]) {
                    pq.push(p);
                }
            }
        }

        vector<int> feed;
        int cnt = 0;
        while (!pq.empty() && cnt < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId][followeeId] = 0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
