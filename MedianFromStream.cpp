class MedianFinder {
public:
    int switcher(int a, int b){
        if(a == b) return 0;
        else if(a > b) return 1;
        return -1;
    }
    priority_queue<int>hpx;
    priority_queue<int, vector<int>, greater<int>>hpi;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        hpx.push(num);
        hpi.push(hpx.top());
        hpx.pop();

        if(hpi.size() > hpx.size()){
            hpx.push(hpi.top());
            hpi.pop();
        }
    }
    
    double findMedian() {
        if(hpi.size() == hpx.size() ) return ((double)hpi.top()+ (double)hpx.top())/2.0;

        return (double)hpx.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */