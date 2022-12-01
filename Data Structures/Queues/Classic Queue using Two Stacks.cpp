class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        s1.push(0); s1.pop();
    }
    
    void push(int x) {
        if (s1.empty()) {
            if (s2.empty()) {
                s1.push(x);
            } else {
                while (!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }
                s1.push(x);
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            s2.push(x);
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        int tmp;
        if (s1.empty()) {
            tmp = s2.top();
            s2.pop();
            return tmp;
        } else {
            tmp = s1.top();
            s1.pop();
            return tmp;
        }
    }
    
    int peek() {
        if (s1.empty()) return s2.top();
        return s1.top();
    }
    
    bool empty() {
        if (s1.empty() && s2.empty()) return true;
        return false;
    }
};
