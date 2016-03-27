
/*
LeetCode: ugly number II
https://leetcode.com/problems/ugly-number-ii/
*/

/*
Use priority_queue and an unordered_set would
bring into unnecessary int overflow
Use `long` type to get rid of this.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long> visited;
        
        if(n==1) {
            return 1;
        }
        //default:max-heap
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        visited.insert(1);
        long top1;
        for(int i=0; i<n; i++) {
            top1 = pq.top();
            pq.pop();
            
            long top2 = top1*2;
            long top3 = top1*3;
            long top5 = top1*5;
            if(visited.count(top2) == 0) {
                visited.insert(top2);
                pq.push(top2);
            }
            if(visited.count(top3) == 0) {
                visited.insert(top3);
                pq.push(top3);
            }
            if(visited.count(top5) == 0) {
                visited.insert(top5);
                pq.push(top5);
            }
        }
        return top1;
    }
};


    int nthUglyNumber(int n) {
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        int pos1=0, pos2=0, pos3=0;

        for(int i=1; i<n; i++) {
            int can1 = dp[pos1]*2;
            int can2 = dp[pos2]*3;
            int can3 = dp[pos3]*5;
            
            int mn = min(can1, min(can2, can3));
            
            if(mn == can1) {
                pos1++;
            }
            if(mn == can2) {
                pos2++;
            }
            if(mn == can3) {
                pos3++;
            }
            dp[i] = mn;
        }        
        return dp[n-1];
    }