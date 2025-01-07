class MyQueue {
public:
    stack<int> s;

    MyQueue() {}

    void push(int x) { s.push(x); }

    int pop() {
        stack<int> s2;
        int val;
        while (!s.empty()) {
            val = s.top();
            s2.push(val);
            s.pop();
        }
        
        s2.pop();

        while (!s2.empty()) {
            s.push(s2.top());
            s2.pop();
        }

        return val;
    }

    int peek() {
        stack<int> s2 = s;
        int val;
        while (!s2.empty()) {
            val = s2.top();
            s2.pop();
        }
        return val;
    }

    bool empty() { return s.empty(); }
};
