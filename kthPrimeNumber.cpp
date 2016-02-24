
/*
LintCode: ugly number 
http://www.lintcode.com/zh-cn/problem/ugly-number/
*/

// solution 1: use priority_queue
// caution duplicate elements
class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        
        priority_queue<long, vector<long>, greater<long>> q;
        unordered_set<long> s;
        q.push(3);
        q.push(5);
        q.push(7);
        s.insert(3);
        s.insert(5);
        s.insert(7);
        long tmp;
        for(int i=0; i<k; i++) {
            tmp = q.top();
            q.pop();
            long t = 3*tmp;
            if(s.find(t) == s.end()) {
                q.push(t);
                s.insert(t);
            }
            t=5*tmp;
            if(s.find(t) == s.end()) {
                q.push(t);
                s.insert(t);
            }
            t=7*tmp;
            if(s.find(t) == s.end()) {
                q.push(t);
                s.insert(t);
            }
        }
        return tmp;
        
        
    }
};