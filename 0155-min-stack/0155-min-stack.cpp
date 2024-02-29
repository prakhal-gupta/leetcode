class MinStack {
    
    stack<int> st,temp;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(temp.empty() || temp.top()>=val)
            temp.push(val);
    }
    
    void pop() {
        if(!st.empty()){
            if(st.top()==temp.top())
                temp.pop();
            st.pop();
        }
    }
    
    int top() {
        return st.empty() ? -1 : st.top();
    }
    
    int getMin() {
        return temp.empty() ? -1 : temp.top();
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