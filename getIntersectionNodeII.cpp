
/*
LintCode: intersection of two linked lists
http://www.lintcode.com/zh-cn/problem/intersection-of-two-linked-lists/#
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    int getLength(ListNode *head) {
        int count = 0;
        ListNode *cur=head;
        while(cur) {
            count++;
            cur = cur->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        ListNode *loA=headA, *loB=headB;
        
        int diff;
        if(lenA > lenB) {
            diff = lenA-lenB;
            while(diff--) {
                loA = loA->next;
            }
        }
        else if(lenA < lenB) {
            diff = lenB-lenA;
            while(diff--){
                loB = loB->next;
            }
        }
        while(loA && loB && loA!=loB) {
            loA=loA->next;
            loB=loB->next;
        }
        if(loA == loB) {
            return loA;
        }
        return NULL;
    }
};


// solution 2
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL || headB == NULL) {
        return NULL;
    }
	//find out the tail of headA
	ListNode *cur = headA;
	while(cur->next) {
		cur=cur->next;
	}
	cur->next = headB;

	ListNode *res=findCycle(headA);
	cur->next = NULL;
	return res;
}

ListNode* findCycle(ListNode *head) {
	if(head == NULL || head->next == NULL) {
		return NULL;
	}
	ListNode *slow = head, *fast = head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast) {
			break;
		}
	}
	if(fast == NULL) {
	    return NULL;
	}
	fast=head;
	while(fast != slow) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
	
}