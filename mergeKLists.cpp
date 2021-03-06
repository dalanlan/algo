
/*
LintCode: merge k sorted lists
http://www.lintcode.com/zh-cn/problem/merge-k-sorted-lists/
*/

// solution 1: divide and conquer
//
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        return mergeKLists(lists, 0, lists.size()-1);
        
    }
    ListNode *mergeKLists(vector<ListNode *> &lists, int lo, int hi) {
        if(lo > hi) {
            return NULL;
        }
        if(lo == hi) {
            return lists[lo];
        }
        
        int mid = (lo+hi)/2;
        ListNode *left = mergeKLists(lists, lo, mid);
        ListNode *right = mergeKLists(lists, mid+1, hi);
        return merge(left, right);
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0); 
        ListNode *tail = dummy;
        
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) {
            tail->next = l1;
        }
        if(l2) {
            tail->next = l2;
        }
        return dummy->next;
    }
};



// solution 2: use a priority_queue

class compare{
    public:
	bool operator()(ListNode *l1, ListNode *l2) {
		if(l1 == NULL) {
			return 1;
		}
		if(l2 == NULL) {
			return 0;
		}
		return l1->val > l2->val;
	}	
};
ListNode *mergeKLists(vector<ListNode*> &lists) {
	if(lists.size() == 0) {
		return NULL;
	}

	priority_queue<ListNode*, vector<ListNode*>, compare> q;
	for(int i=0; i<lists.size(); i++) {
		if(lists[i]) {
			q.push(lists[i]);
		}
	}
	ListNode *tmp;
	ListNode *dummy = new ListNode(0);
	ListNode *tail = dummy;
	while(!q.empty()) {
		tmp = q.top();
		q.pop();
		tail->next = tmp;
		tail = tail->next;
		if(tmp->next) {
			q.push(tmp->next);
		}
	}
	return dummy->next;


// huge merge sort
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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) {
            tail->next = l1;
        }
        if(l2) {
            tail->next = l2;
        }
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        if(lists.size() == 1) {
            return lists[0];
        }
        vector<ListNode*> res;
        
        for(int i=0; i<lists.size(); i+=2) {
            if(i+1< lists.size()) {
                res.push_back(merge(lists[i], lists[i+1]));    
            }
            else {
                res.push_back(lists[i]);
            }
        }
        
        return mergeKLists(res);
    }
};


// solution 3: rewrite

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
    
    
    class compare {
        public:
            bool operator() (ListNode *l1, ListNode *l2) {
                return l1->val > l2->val;
            }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i]) {
                pq.push(lists[i]);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while(!pq.empty()) {
        
            tail->next = pq.top();
       
            pq.pop();
            tail = tail->next;
            if(tail->next) { 
                pq.push(tail->next);
            }
             
        }
        return dummy->next;
    }
};