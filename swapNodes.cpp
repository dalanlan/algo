
/*
LintCode: swap two nodes in linked list
http://www.lintcode.com/zh-cn/problem/swap-two-nodes-in-linked-list/
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
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
     
    // WA: You should swap the nodes, do not directly swap the values;
    // AC
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        if(head == NULL || v1 == v2) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        
        ListNode *p1=head, *prev1 = dummy;
        while(p1 && p1->val != v1) {
            prev1 = prev1->next;
            p1 = p1->next;
        }
        if(!p1) {
            return head;
        }
      
        ListNode *p2=head, *prev2 = dummy;
        while(p2 && p2->val != v2) {
            prev2 = prev2->next;
            p2 = p2->next;
            
        }
        if(!p2) {
            return head;
        }
       
        
        prev1->next = p2;
        prev2->next = p1;

        ListNode *tmp = p2->next;
        p2->next = p1->next;
        p1->next = tmp;
        
        return dummy->next;
      
        
    }
};


// AC

     ListNode* swapNodes(ListNode* head, int v1, int v2) {
         if(v1 == v2 || head == NULL) {
             return head;
         }
         ListNode *prev1=NULL, *p1=head;
         while(p1 && p1->val != v1) {
             prev1 = p1;
             p1 = p1->next;
         }
         if(!p1) {
             return head;
         }
         ListNode *prev2 = NULL, *p2 = head;
         while(p2 && p2->val != v2) {
             prev2 = p2;
             p2 = p2->next;
         }
         if(!p2) {
             return head;
         }
         
         if(prev1) {
             prev1->next = p2;
         }
         else {
             head = p2;
         }
         if(prev2) {
             prev2->next = p1;
         }
         else {
             head = p1;
         }
         
         ListNode* tmp = p2->next;
         p2->next=p1->next;
         p1->next=tmp;
         return head;
     }