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
        if(st.empty())
            return;
        if(st.top()==temp.top())
            temp.pop();
        st.pop();
    }
    
    int top() {
       if(st.empty())
           return -1;
        return st.top();
    }
    
    int getMin() {
        if(temp.empty())
            return -1;
        return temp.top();
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