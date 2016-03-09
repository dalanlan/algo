

/*
LeetCode: LRU Cache
https://leetcode.com/problems/lru-cache/
*/

// solution 1: TLE
// use a singly-list && unordered_map
class LRUCache{
public:
class ListNode1 {
      public:
        int key;
        int val;
        ListNode1* next;
        ListNode1(int k, int v) {
            key = k;
            val = v;
            next = NULL;
        }
        
    };
    int size;
    int count = 0; // valid item
    ListNode1* root=NULL;
    unordered_map<int, ListNode1*> map;
    
    
    void deleteNode(ListNode1* node) {
        if(!root) {
            return;
        }
        if(root == node) {
            root = root->next;
            return;
        }
        ListNode1* find = root;
        while(find->next && find->next != node) {
            find=find->next;
        }
        if(find->next == NULL) {
            return;
        }
        find->next = node->next;
        // delete(node);
        return;
        
    }
    void insertNode(ListNode1* node) {
        if(!root) {
            root = node;
            return;
        }
        ListNode1* tail = root;
        while(tail->next) {
            tail = tail->next;
        }
        tail->next = node;
    }
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(map.count(key) == 1) {
            ListNode1* cur = map[key];
            int val = cur->val;
            deleteNode(cur);
            insertNode(new ListNode1(key, val));
            return val;
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if(map.count(key) == 1) {
            ListNode1* oldNode = map[key];
            deleteNode(oldNode);
            ListNode1* newNode = new ListNode1(key, value);
            insertNode(newNode);
            map[key]=newNode;
            return;
            
        }
        else {
            ListNode1* cur = new ListNode1(key, value);
            if(count<size) {
               count++;
            }
            else {
                map.erase(root->key);
                deleteNode(root);
            }
            insertNode(cur);
            map[key]=cur;
        }
        
    }
};

// solution 2: We must use a double-linked
// list to solve this problem


class LRUCache {
	public:

	list<pair<int, int>> lis;
	unordered_map<int, list<pair<int,int>>::iterator> map;
	int capa;

	LRUCache(int capacity) {
		capa = capacity;
	}
	int get(int key) {
		if(map.count(key) == 1) {
			lis.splice()
		}
	}
}