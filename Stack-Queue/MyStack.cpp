class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        while (sz > 1) {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
