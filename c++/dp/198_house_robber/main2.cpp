/*
 * Filename: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters
 * Created Date: Tuesday, May 14th 2019, 6:49:25 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */

#include "../../include/base.h"

/// dp: Iterative + 2 variables (bottom-up) 
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int prev2 = 0;
        int prev1 = 0;
        int num = nums[0];
         for(int i = 1; i < nums.size(); i++)  {
             prev1 = num;
             num = max((prev2+nums[i]), prev1);
             prev2 = prev1;
         }
         return num;
    }

};


int main() {
    vector<int>  first;
    int expectAns;

    first = {1,2,3,1};
    expectAns = 4;
    TEST_SMP1(Solution, rob, expectAns, first);

    first = {2,7,9,3,1};
    expectAns = 12;
    TEST_SMP1(Solution, rob, expectAns, first);


    first = { 10, 0, 1, 100};
    expectAns = 110;
    TEST_SMP1(Solution, rob, expectAns, first);

    first = { 2,7,9,3,1,4};
    expectAns = 15;
    TEST_SMP1(Solution, rob, expectAns, first);

    return 0;
}
