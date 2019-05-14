/*
 * Filename: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters
 * Created Date: Tuesday, May 14th 2019, 6:49:25 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */

#include "../../include/base.h"

/// dp: Recursive (top-down)
/// Time Complexity: O(n)
/// Space Complexity: O(n)
// class Solution {
// private:
//     int rob(vector<int>& nums, int start)  {
//         if(start < 0)  {
//             return 0;
//         }
//         return max(rob(nums, start-2) + nums[start], rob(nums, start-1));
//     }
// public:
//     int rob(vector<int>& nums) {
//         if (nums.size() == 0) return 0;
//         return rob(nums, nums.size() - 1) ;
//     }
// };



/// dp: Recursive + memo (top-down)
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
private:
    int rob(vector<int>& nums, int start, vector<int>& dp)  {
        if(start < 0)  {
            return 0;
        }
        if (dp[start] > 0) {
        return dp[start];
        }     
        int result = max(rob(nums, start-2, dp) + nums[start], rob(nums, start-1, dp));
        dp[start] = result;
        return result;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 0) return 0;
        return rob(nums, nums.size() - 1, dp) ;
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
