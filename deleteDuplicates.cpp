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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
            
        ListNode* cur=head;
        ListNode* next = cur->next;
        set<int> reDup;
        reDup.insert(cur->val);
        while(next)
        {
            if(reDup.find(next->val) == reDup.end())
            {
                reDup.insert(next->val);
                cur = next;
                next = cur->next;
            }
            else
            {
                    cur->next = next->next;
                    next = cur->next;
            }
        }
        
        return head;
        
        
        
    }
};