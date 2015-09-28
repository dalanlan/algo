queue<int> in;
queue<int> out;
// Push element x onto stack.
void push(int x) {
    in.push(x);
}

// Removes the element on top of the stack.
void pop() {
    while(in.size()>1)
    {
        int top = in.front();
        in.pop();
        out.push(top);
    }
    in.pop();
    queue<int> tmp = in;
    in = out;
    out = tmp;
}

// Get the top element.
int top() {
    while(in.size()>1)
    {
        int top = in.front();
        in.pop();
        out.push(top);
    }
    int front = in.front();
    in.pop();
    out.push(front);
    
    queue<int> tmp = in;
    in = out;
    out = tmp;
    return front;
    
}

// Return whether the stack is empty.
bool empty() {
    return in.empty();
}