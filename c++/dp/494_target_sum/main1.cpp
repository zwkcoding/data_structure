/*
 * Filename: /home/zwk/code/datafirst
 *uctrue/c++/stack/evaluate_reverse_polish_notation/main.cpp
 * Path: /home/zwk/code/datafirst
 *uctrue/c++/stack/evaluate_reverse_polish_notation
 * Created Date: Wednesday, May 1st 2019, 5:38:35 pm
 * Author: zwk
 * 
 * ref: https://leetcode.com/problems/target-sum/discuss/97369/Evolve-from-brute-force-to-dp
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
#include <array>

/// Recursion with memoization
/// Time Complexity:  O(l*n) The memomemo array of size l*n has been filled just once. Here, l refers to the range of sumsum and n refers to the size of numsnums array.
/// Space Complexity: O(n). The depth of the recursion tree can go upto n

/*
A call to find() with the same start index and target sum can be made multiple times.
 We can use a 2d table to cache the result to avoid duplicate calls with the same state.
*/
class Solution {
private:
    int find(int p, vector<int>& nums, int sum, vector<unordered_map<int,int>>& mem) {
        // find sum = s, equal to : sum -s = 0
        if(p==nums.size()) return sum == 0;
        auto it = mem[p].find(sum);
        if(it != mem[p].end()) return it->second;
        return mem[p][sum]=find(p+1,nums,sum+nums[p],mem)+find(p+1,nums,sum-nums[p],mem);
    }
public:
    int findTargetSumWays(vector<int>& nums, int s)  {
        vector<unordered_map<int,int>> mem(nums.size());
        return find(0, nums, s, mem);
    }

     // O(ns) 
     //  use hashtable to visit valid states only
     /*
      int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0]=1;
        for(int i = 0; i < nums.size(); i++)  {
            for(auto p : dp[i])  {
                dp[i+1][p.first + nums[i]] += p.second;     // p.second reperensents combination quantity when last_sum = p.first
                dp[i+1][p.first - nums[i]] += p.second;
            }
        }
        return dp[nums.size() ][S];
      }
      */
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
