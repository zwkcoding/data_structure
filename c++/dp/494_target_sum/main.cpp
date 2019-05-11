/*
 * Filename: /home/zwk/code/datafirst
 *uctrue/c++/stack/evaluate_reverse_polish_notation/main.cpp
 * Path: /home/zwk/code/datafirst
 *uctrue/c++/stack/evaluate_reverse_polish_notation
 * Created Date: Wednesday, May 1st 2019, 5:38:35 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */


/*
e.g1
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Input: nums is [1, 2, 3, 4, 5], S is 5. 
Output: 3
Explanation: 

+1-2-3+4+5 = 5
+1+2+3+4-5 = 5
-1+2+3-4+5 = 5

There are 3 ways to assign symbols to make the sum of nums be target 5.
*/

#include "../../include/base.h"

///  brute force approach based on recursion dfs 
/// Time Complexity: O(2^n). Size of recursion tree will be 2^n 
/// Space Complexity: O(n). The depth of the recursion tree can go upto n
class Solution {
private:
    int dfs(vector<int>& nums, int index, int res, int s)  {
        if(index == nums.size())  {
            return res == s;
        }
        int ans  = 0;
        ans += dfs(nums, index+1, res - nums[index], s);
        ans += dfs(nums, index+1, res + nums[index], s);
        return ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int s)  {
        return dfs(nums, 0, 0, s);
    }


};


int main() {
    vector<int> first;
    int second;
    int ans, expectAns;

    first.clear();
    first.push_back(1);
    first.push_back(1);
    first.push_back(1);
    first.push_back(1);
    first.push_back(1);
    second = 3;
    expectAns = 5;
    TEST_SMP2(Solution, findTargetSumWays, expectAns, first, second);

    first.clear();
    first.push_back(1); 
    first.push_back(2);
    first.push_back(3);
    first.push_back(4);
    first.push_back(5);

    second = 5;
    expectAns = 3;
    TEST_SMP2(Solution, findTargetSumWays, expectAns, first, second);


    return 0;
}
