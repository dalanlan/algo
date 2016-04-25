
/*
LintCode: reorder list
http://www.lintcode.com/zh-cn/problem/reorder-list/
*/

// use function to merge two ListNode 
// that would never change the original ListNode head
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
     * @param head: The first node of linked list.
     * @return: void
     */
    ListNode *reverse(ListNode *head) {
        ListNode *pre = NULL, *cur = head, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    void merge(ListNode *head, ListNode *right) {
        bool isLeft = true;
        ListNode *dummy = new ListNode(0);
        while(head && right) {
            if(isLeft) {
                dummy->next = head;
                head = head->next;
            }
            else {
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
            isLeft = !isLeft;
        }
        if(head) {
            dummy->next = head;
        }
        else {
            dummy->next = right;
        }
    }
    void reorderList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) {
            return;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *right = reverse(slow->next);
        slow->next = NULL;
        merge(head, right);
        
    }
};


// recursive way
// kinda clean, yet TLE


// solution 3: kinda crap
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
    ListNode* reverse(ListNode *head) {
        ListNode *prev = NULL, *cur = head, *next=NULL;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next) {
            return;
        }
        // find the middle of the list 
        // reverse the second part
        // merge it
        ListNode *fast=head, *slow=head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //reverse slow->next
        ListNode* right = reverse(slow->next);
        slow->next=right;
        
        ListNode* left = head;
        while(left != slow) {
            slow->next = right->next;
            right->next= left->next;
            left->next= right;
            left = right->next;
            right = slow->next;
        }
    }
};