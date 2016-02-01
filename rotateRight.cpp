
/*
LintCode: rotate linked list
http://www.lintcode.com/zh-cn/problem/rotate-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
     

    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(head == NULL || k == 0) {
            return head;
        }
        
        // count the len
        // find the tail
        int len = 0;
        ListNode *tail = head;
        while(tail->next) {
            len++;
            tail = tail->next;
        }
        len++;
        if(len == 1) {
            return head;
        }
        int m = len - (k%len);
        if(m == len) {
            return head;
        }
        ListNode* cur = head;
        // cur is the new tail
        while(m>1) {
            cur = cur->next;
            m--;
        }
        
        // res is the new head
        ListNode *res = cur->next;
        
        ListNode *tmp = head;
        cur->next = NULL;
        tail->next = tmp;
        return res;
        
    }
};