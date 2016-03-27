

/*
LeetCode: find median from data stream
https://leetcode.com/problems/find-median-from-data-stream/
*/

class MedianFinder {
public:

    // // overflow issue
    // // tow priority_queue
    // // max-heap: smaller half of the number
    // priority_queue<int> maxPQ;
    // // min-heap: larger half of the number
    // priority_queue<int, vector<int>, greater<int>> minPQ;
    
    priority_queue<long> small, large;
    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        
        if(small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
        
    }

    // Returns the median of current data stream
    double findMedian() {
        if(small.size() > large.size()) {
            return small.top();
        }
        else {
            return (small.top()-large.top())/2.0;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();