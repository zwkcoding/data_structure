class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(!stack2.empty())  {
            int ans = stack2.top();
            stack2.pop();
            return ans;
        }
        while(!stack1.empty())  {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ans = stack2.top();
        stack2.pop();
        return ans;
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
