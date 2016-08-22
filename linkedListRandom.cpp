
/*
Leetcode: linked list random node
https://leetcode.com/problems/linked-list-random-node/
*/
class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        node = head; 
        // _len = len(head);
    }
    
    ListNode* node;
    /*
    vector<int> num;
    int _len;
    
    int len(ListNode* head) {
        int cnt = 0;
        ListNode* cur = head;
        while(cur) {
            cnt++;
            num.push_back(cur->val);
            cur = cur->next;
            
        }
        return cnt;
    }
    */
    /** Returns a random node's value. */
    int getRandom() {
        
        ListNode* cur = node;
        int res = cur->val;
        for(int i=1; cur != NULL; i++) {
            if(rand()%i == 0) {
                res = cur->val;
            }
            cur = cur->next;
        }
        return res;
        // return num[rand()%_len];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */