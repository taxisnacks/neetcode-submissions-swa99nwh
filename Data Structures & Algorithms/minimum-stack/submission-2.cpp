class MinStack {
public:
    stack<int> stk;
    stack<int> minStack;
    MinStack() {

    }
    
    void push(int val) { // This solution works because the actual values matching doesnt matter in minStack, just whatever the min is at that layer
        stk.push(val);
        val = min(val, minStack.empty() ? val : minStack.top()); // Compare val and current minimum stack
        minStack.push(val); // 
    }
    
    void pop() {
        stk.pop();
        minStack.pop(); // must keep them synced in order for mins to match
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() { 
        return minStack.top();
    }
};
