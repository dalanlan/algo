
/*
LintCode: rehashing
http://www.lintcode.com/en/problem/rehashing/
*/

// just do it 
// no particular tricks

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        
        int sz = hashTable.size();
        if(sz == 0) {
            return vector<ListNode*> {};
        }
        int cap = sz*2;
        vector<ListNode*> res(cap, NULL);
        
        for(int i=0; i<sz; i++) {
            if(hashTable[i] != NULL) {
                ListNode* head = hashTable[i];
                while(head) {
                    int mod = (head->val % cap + cap) % cap;
                    ListNode* tail = new ListNode(head->val);
                    if(res[mod] == NULL) {
                        res[mod] = tail;
                    }
                    else {
                        ListNode *cur = res[mod];
                        while(cur->next) {
                            cur = cur->next;
                        }
                        cur->next=tail;
                    }
                    head = head->next;
                }
            }
        }
        return res;
    }
};
