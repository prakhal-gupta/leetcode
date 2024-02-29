class MinStack {
    stack<long long> st; // Use long long for the stack
    long long mine;      // Use long long for the minimum value
public:
    MinStack() {
        mine = INT_MAX;
    }
    
    void push(int val) {
        long long a = val; // Use long long for intermediate calculation
        if (val < mine) {
            a = 2LL * val - mine; // Use LL to ensure multiplication with long long
            mine = val;
        }   
        st.push(a);
    }
    
    void pop() {
        if (st.empty()) // Check if the stack is empty
            return;

        long long topElement = st.top();
        st.pop();

        // If the top element was originally smaller than the current minimum,
        // update the current minimum
        if (topElement < mine) {
            mine = 2LL * mine - topElement; // Use LL to ensure multiplication with long long
        }
    }
    
    int top() {
        if (st.empty()) // Check if the stack is empty
            return -1;

        long long topElement = st.top();

        // If the top element was originally smaller than the current minimum,
        // return the original value instead of the transformed value
        return topElement < mine ? static_cast<int>(mine) : static_cast<int>(topElement);
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