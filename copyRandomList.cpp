
/*
LintCode: copy list with random pointer
http://www.lintcode.com/zh-cn/problem/copy-list-with-random-pointer/
*/

/*
deep copy: a totally brand new lists
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */

     // solution 1: map + two-pass
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        
        // map + two-pass 
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *res = dummy;
        unordered_map<RandomListNode*, RandomListNode*> myMap;
        
        while(head) {
            res->next = new RandomListNode(head->label);
            res = res->next;
            myMap[head] = res;
            if(head->random) {
                res->random = head->random;
            }
            head = head->next;
        }
        
        RandomListNode *cur=dummy->next;
        while(cur) {
            if(cur->random) {
                cur->random = myMap[cur->random];
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};

