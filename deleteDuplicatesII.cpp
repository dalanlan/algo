
/*
Lintcode: remove duplicates from sorted list ii
http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list-ii/
*/


// solution 1: map + two-pass
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        unordered_map<int, int> myMap;
        
        ListNode *cur = head;
        while(cur) {
            if(myMap.count(cur->val) > 0) {
                myMap[cur->val]++;
            }
            else {
                myMap[cur->val]=1;
            }
            cur = cur->next;
        }
        
        ListNode *dummy = new ListNode(0);
        ListNode *curNode = dummy;
        cur = head;
        while(cur) {
            if(myMap[cur->val] == 1) {
                curNode->next = cur;
                curNode = curNode->next;
            }
            cur = cur->next;
        }
        curNode->next = NULL;
        return dummy->next;
        
    }
};