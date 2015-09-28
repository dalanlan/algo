/*
http://stackoverflow.com/questions/688276/implement-stack-using-two-queues
*/

//Solution 1: Version A
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

//Solution 2: Version B
queue<int> q1;
queue<int> q2;

void push(int x){
    q2.push(x);
    while(!q1.empty())
    {
        int top = q1.front();
        q1.pop();
        q2.push(top);
    }
    queue<int> tmp = q1;
    q1 = q2;
    q2 = tmp;
}

void pop(){
    q1.pop();
}
int top(){
    return q1.front();
}
bool empty(){
    return q1.empty();
}

//Solution 3
queue<int> q;

void push(int x){
    q.push(x);
}
void pop(){
    for(int i = 0; i<q.size()-1;i++)
    {
        int top = q.front();
        q.pop();
        q.push(top);
    }
    q.pop();
}
int top(){
    int top;
    for(int i=0;i<q.size()-1;i++)
    {
        top = q.front();
        q.pop();
        q.push(top);
    }
    top = q.front();
    q.pop();
    q.push(top);
    return top;
}
bool empty(){
    return q.empty();
}