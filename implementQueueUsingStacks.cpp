stack<int> in;
stack<int> out;
// Push element x to the back of queue.
void push(int x) {
    in.push(x);
}

// Removes the element from in front of queue.
void pop(void) {
    if(out.empty())
    {
        while(!in.empty())
        {
        int top = in.top();
        in.pop();
        out.push(top);
        }
    }
    out.pop();
}

// Get the front element.
int peek(void) {
    if(out.empty())
    {
        while(!in.empty())
        {
        int top = in.top();
        in.pop();
        out.push(top);
        }
    }
    return out.top();
}

// Return whether the queue is empty.
bool empty(void) {
    return in.empty() && out.empty();
}