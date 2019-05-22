class Solution {
private:
    stack<int> stk1, stk2; 
public:
    void push(int value) {
        stk1.push(value);  
        if(stk2.size( ) == 0)
        {
            stk2.push(value);
        }
        else if(stk2.top() >= value)  {
            stk2.push(value);    // update stk2
        }
    }
    void pop() {
        int a = stk1.top();
        stk1.pop();
        if(a == stk2.top())  {
            stk2.pop();  // when top one the min, update stk2
        }
        else ;  // not to change stk2
    }
    int top() {
        return stk1.top();
    }
    int min() {
        if(stk1.empty())
        {
            return 0;
        }
        return stk2.top();
        
    }
};
