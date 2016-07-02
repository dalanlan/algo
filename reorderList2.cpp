
/*
LeetCode: reorder List
https://leetcode.com/problems/reorder-list/
*/


// solution 1: recursive
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // TLE
 // recursive
class Solution {
public:
    ListNode* reorder(ListNode* head) {
        if(!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode *tailPrev = head;
        while(tailPrev->next->next) {
            tailPrev = tailPrev->next;
        }
        ListNode *tail = tailPrev->next;
        tailPrev->next = NULL;
        tail->next = reorder(head->next);
        head->next = tail;
        return head;
    }
    void reorderList(ListNode* head) {
        reorder(head);
    }
};


// AC
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
    
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *cur = head, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    void merge(ListNode* head1, ListNode* head2) {
        
        ListNode *node1 = head1, *node2 = head2;
       
        
        ListNode *res = node1;
        node1 = node1->next;
            
        // order matters
        while(node1 && node2) {
            res->next = node2;
            // important!
            node2 = node2->next;

            res = res->next;

            res->next = node1;
            // important!
            node1 = node1->next;
            res = res->next;
        }
        if(node1) {
            res->next = node1;
        }
        if(node2) {
            res->next = node2;
        }
         
    }
    
    void reorderList(ListNode* head) {
        
        // cut from the half
        if(!head || !head->next) {
            return;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast= head, *slow = dummy;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *second = slow->next;
        slow->next = NULL;
        ListNode *sec = reverse(second);
        
        merge(head, sec);
        return;
    }
};