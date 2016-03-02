
/*
LintCode: min stack
http://www.lintcode.com/zh-cn/problem/min-stack/
*/

// solution 1: cost double space complexity

class MinStack {
public:
    
    stack<int> num;
    stack<int> minNum;
    // solution 1: double the space complexity
    MinStack() {
        // do initialization if necessary
        
        
        
    }

    void push(int number) {
        // write your code here
        num.push(number);
        int tmp;
        if(minNum.empty()) {
            tmp = number;
        }
        else {
            tmp = number<minNum.top()?number:minNum.top();
        }
        minNum.push(tmp);
    }

    int pop() {
        // write your code here
        int tmp = num.top();
        num.pop();
        minNum.pop();
        return tmp;
    }

    int min() {
        // write your code here
        return !minNum.empty()?minNum.top():INT_MAX;
    }
};

// solution 2: Use min stack to store min element
// only update the stack when the popped element 
// is small enough

    void push(int number) {
        num.push(number);
        
        if(minNum.empty()) {
            minNum.push(number);
        }
        else if(number <= minNum.top()) {
                minNum.push(number);
        }
    }
    
    int pop() {
        int tmp = num.top();
        num.pop();
        if(tmp == minNum.top()) {
            minNum.pop();
        }
        
        return tmp;
    }
    int min() {
        return minNum.top();
    }