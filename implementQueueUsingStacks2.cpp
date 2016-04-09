
/*
Leetcode: implement queue using stacks
https://leetcode.com/problems/implement-queue-using-stacks/
*/

class Queue {
public:
    stack<int> s1;
    stack<int> s2;
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!s2.empty()) {
            s2.pop();
            return;
        }
        else {
            while(!s1.empty()) {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
            int res = s2.top();
            s2.pop();
            return;
        }
    }

    // Get the front element.
    int peek(void) {
        if(!s2.empty()) {
            return s2.top();
        }
        else {
            while(!s1.empty()) {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
            return s2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};