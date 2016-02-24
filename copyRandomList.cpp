
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


// solution 2: map + one-pass

RandomListNode *copyRandomList(RandomListNode *head) {
        // map + one-pass
        
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *cur = dummy;
        unordered_map<RandomListNode*, RandomListNode*> myMap;
        
        while(head) {
            if(myMap.find(head) != myMap.end()) {
                cur->next = myMap[head];
            }
            else {
                cur->next = new RandomListNode(head->label);
                myMap[head] = cur->next;
            }
            if(head->random) {
                if(myMap.find(head->random) != myMap.end()) {
                    cur->next->random = myMap[head->random];
                }
                else {
                    cur->next->random = new RandomListNode(head->random->label);
                    myMap[head->random] = cur->next->random;
                }
            }
            cur = cur->next;
            head = head->next;
        }
        return dummy->next;
    }