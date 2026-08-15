class MyQueue {
private:
    stack<int> input;
    stack<int> output;

    void peekMove() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        peekMove();
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        peekMove();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
