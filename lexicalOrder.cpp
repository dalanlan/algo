/*
Leetcode: lexicographical numbers
https://leetcode.com/problems/lexicographical-numbers/
*/

// solution 1: TLE
class Solution {
public:
    class compare {
        public:
            bool operator()(int n1, int n2) {
                string s1=to_string(n1);
                string s2=to_string(n2);
                
                int p1=0, p2=0;
                while(p1<s1.size() && p2<s2.size() && s1[p1] == s2[p2]) {
                    p1++;
                    p2++;
                }
                return p1==s1.size() || p2 < s2.size() && s1[p1] < s2[p2];
            }
    };
    vector<int> lexicalOrder(int n) {
        vector<int> num(n, 0);
        for(int i=0; i<n; i++) {
            num[i] = i+1;
        }
        sort(num.begin(), num.end(), compare());
        return num;
    }
};


// solution 2: AC
// dfs
    void dfs(int k, vector<int> &num, int n) {
        if(k<=n) {
            num.push_back(k);
            int t = k*10;
            if(t <= n) {
                for(int i=0; i<10; i++)
                dfs(t+i, num, n);
            }
        }
        
    }
    vector<int> lexicalOrder(int n) {
        vector<int> num;
        for(int i=1; i<10; i++) {
            dfs(i, num, n);
        }
        return num;
        
    }
