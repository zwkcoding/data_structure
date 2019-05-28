class Solution {
public:
    int Add(int num1, int num2)
    {
        int diff_value = num1 ^ num2;
        int plus_value = (num1 & num2) << 1;
        if(plus_value == 0) return diff_value;
        return Add(diff_value, plus_value);
    }
};
