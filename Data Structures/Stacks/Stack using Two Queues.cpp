class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        q1.push(0); q1.pop();
    }
    
    void push(int x) {
        if (q1.empty()) {
           if (q2.empty()) q1.push(x);
           else {
               q1.push(x);
               while (!q2.empty()) {
                   q1.push(q2.front());
                   q2.pop();
               }
           }
        } else if (q2.empty()) {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        int tmp;
        if (q1.empty()) {
            tmp = q2.front();
            q2.pop();
            return tmp;
        } else {
            tmp = q1.front();
            q1.pop();
            return tmp;
        }
    }
    
    int top() {
        if (q1.empty()) return q2.front();
        else return q1.front();
    }
    
    bool empty() {
        if (q1.empty() && q2.empty()) return true;
        return false;
    }
};
