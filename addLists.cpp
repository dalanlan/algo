
/* 
Lintcode 167: add lists
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1, *p2 = l2, *p3=NULL, *head=NULL;
        
        int val, carry = 0;
        while(p1 != NULL || p2 != NULL) {
            val = (p1 == NULL?0:p1->val) + (p2==NULL?0:p2->val) + carry;
            ListNode *tmp = new ListNode(val%10);
            carry = val/10;
            if(p3 == NULL) {
                p3 = tmp;
                head = p3;
            }
            else {
                p3->next = tmp;
                p3 = p3->next;
            }
            if(p1 != NULL)p1 = p1->next;
            if(p2 != NULL)p2 = p2->next;
        }
        if(carry > 0) {
            p3->next = new ListNode(carry);
        }
        return head;
    }
};