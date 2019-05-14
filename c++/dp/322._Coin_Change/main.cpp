/*
 * Filename: /home/zwk/code/data_structrue/c++/dp/322._Coin_Change/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/dp/322._Coin_Change
 * Created Date: Tuesday, May 14th 2019, 8:18:41 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */


#include "../../include/base.h"

/// ref to : https://leetcode.com/problems/coin-change/discuss/77373/6-7-lines-2-ways
/// DP:  Iterative + memo (bottom-up)
/// Time Complexity: O(n*m)
/// Space Complexity: O(m)
class Solution {
public:
      int coinChange(vector<int>& coins, int amount) {
          vector<int> dp(amount+1, amount+1);
          dp[0] = 0;
          for(int i = 1; i <= amount; i++)  {
              for(auto coin: coins)  {
                  if(coin <= i)  {
                      dp[i] = min(dp[i], dp[i - coin] + 1);         // ``dp[i - coin] + 1`` --> the combination that has the fewest number of coins 
                  }
              }
          }
          return dp.back()>amount ? -1 : dp.back();
      }
};


int main() {
    vector<int>  first;
    int second;
    int expectAns;

    first = {1,2,5};
    second = 11;
    expectAns = 3;
    TEST_SMP2(Solution, coinChange, expectAns, first, second);

    first = {1,2,5};
    second = 5;
    expectAns = 1;
    TEST_SMP2(Solution, coinChange, expectAns, first, second);

    first = {2};
    second = 3;
    expectAns = -1;
    TEST_SMP2(Solution, coinChange, expectAns, first, second);

    return 0;
}
