
/*
LintCode 372:
Delete an element in the linked list
with O(1) complexity
*/

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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        
        if(node->next != NULL) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
        else {
            node = NULL;
        }
    }
};