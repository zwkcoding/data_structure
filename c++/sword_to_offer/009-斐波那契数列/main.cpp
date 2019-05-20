class Solution {
public:
    int Fibonacci(int n) {
        long pre_pre = 0;
        long pre = 1;
        long cur = 1;
        if(n < 2) return n;  
        for(int i = 2; i <= n; i++)  {
            cur = pre +  pre_pre;
            pre_pre = pre;
            pre = cur;
        }
        return cur;
    }
};
