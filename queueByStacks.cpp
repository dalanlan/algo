
/* 
LintCode: implement queue by two stacks
http://www.lintcode.com/zh-cn/problem/implement-queue-by-two-stacks/
*/
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        stack1.push(element);
        // write your code here
    }
    
    int pop() {
        if(!stack2.empty()) {
            int tmp = stack2.top();
            stack2.pop();
            return tmp;
            
        }
        else {
            int tmp;
            while(!stack1.empty()) {
                tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
            stack2.pop();
            return tmp;
        }
        // write your code here
    }

    int top() {
        // write your code here
        if(!stack2.empty()) {
            return stack2.top();
        }
        else {
            while(!stack1.empty()) {
                int tmp =stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
            return stack2.top();
        }
    }
};
