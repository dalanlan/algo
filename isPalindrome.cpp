ListNode* ReverseList(ListNode* head){
    ListNode *cur,*pre,*next;
    cur = head;
    pre = NULL;
    while(cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    
    if (head == NULL)
        return true;
    //find the middle node
    ListNode *fast=head,*slow=head;
    
    
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    
    ListNode* otherpart = ReverseList(slow);
    while(otherpart)
    {
        if(otherpart->val != head->val)
            return false;
        otherpart = otherpart->next;
        head = head->next;
    }
    return true;
    
}