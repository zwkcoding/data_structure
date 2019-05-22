class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size( ) == 0 || popV.size( ) == 0)
        {
            return false;
        }
        stack<int> s;
        int push, pop;
        s.push(pushV[0]); // init 
        for(push = 0, pop = 0; push < pushV.size() && pop < popV.size();)  {
            if(!s.empty())  {
                if(s.top() == popV[pop])  {
                    // 出栈
                    s.pop();
                    pop++;
                } else {
                    // 入栈
                    s.push(pushV[++push]);
                }
            }
            else {
                // 入栈
                s.push(pushV[++push]);
            }
        }
        
       if(s.empty())  {
           return true;
       } else  {
           return false;
       }
    }
};
