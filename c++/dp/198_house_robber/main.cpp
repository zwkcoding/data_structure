/*
 * Filename: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters
 * Created Date: Tuesday, May 14th 2019, 6:49:25 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */

#include "../../include/base.h"

/// ref to : https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
/// DP:  Iterative + memo (bottom-up)
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i < nums.size(); i++)  {
            dp[i+1] = max((dp[i-1]+nums[i]), dp[i]);
        }
        return dp[nums.size()];
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

    return 0;
}
