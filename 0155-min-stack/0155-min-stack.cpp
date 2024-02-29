class MinStack {
    stack<long long> st;
    long long mine;
public:
    MinStack() {
        mine = INT_MAX;
    }
    
    void push(int val) {
        long long a = val;
        if (val < mine) {
            a = 2LL * val - mine;
            mine = val;
        }   
        st.push(a);
    }
    
    void pop() {
        if (st.empty())
            return;
        if (st.top() < mine) {
            mine = 2LL * mine - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.empty())
            return -1;
        return st.top() < mine ? static_cast<int>(mine) : static_cast<int>(st.top());
    }
    
    int getMin() {
        return static_cast<int>(mine);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */