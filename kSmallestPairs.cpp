
/*
Leetcode: Find K pairs with smallest sums
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
*/

class Solution {
public:
    class Node{
    public:
        int i;
        int j;
        int val;
        Node(int ind1, int ind2, int v) {
            i = ind1;
            j = ind2;
            val = v;
        } 
    };
    
    struct Compare {
        bool operator()(Node *n1, Node *n2) { 
            return n1->val > n2->val;
        }
    };
    
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        if(sz1 == 0 || sz2 == 0 || k == 0) {
            return {};
        }
        priority_queue<Node*, vector<Node*>, Compare> pq;
        vector<pair<int, int>> res;
        pq.push(new Node(0, 0, nums1[0]+nums2[0]));
        int cnt = 0;
        
        while(!pq.empty() && cnt < k) {
            Node* tmp = pq.top();
            pq.pop();
            
            int ind1 = tmp->i;
            int ind2 = tmp->j;
            res.push_back({nums1[ind1], nums2[ind2]});
            cnt++;
            
            if(ind2 + 1 < sz2) { 
                pq.push(new Node(ind1, ind2+1, nums1[ind1]+nums2[ind2+1]));
            }
            if(ind2 == 0 && ind1 +1 < sz1) {
                pq.push(new Node(ind1+1, ind2, nums1[ind1+1]+nums2[ind2]));
            }
        }
        return res;
    }
    };