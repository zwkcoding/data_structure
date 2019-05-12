/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include "../../include/base.h"

/// Time Complexity:  O(min(m, n)) 
/// Space Complexity: O(1).
class Solution {
public:
    int uniquePaths(int m, int n) {
        // C(m + n - 2, m-1) or C(m + n - 2, n - 1)
        /*
           n decreasing factors, starting with m   m(m-1)...(m-n+1)
  C(m,n) = -------------------------------------  = ------------------
           n decreasing factors, starting with n   n(n-1)...(3)(2)(1)

        if(m <=0 || n <= 0) return 0;
        long long res = 1;
        for(int i = n; i < m+n-1 ; i++){
            res = res * i / (i- n + 1);
        }
        return (int)res;
        */
        int x = std::min(m, n) - 1;
        long up = 1, down = 1; 
        for(int i = m + n -2; i > m + n - 2 - x; i--)  {
            up *= i;
        }
        for(int j = x; j > 0; j--)  {
            down *= j;
        }
        return up / down;
    }
};


int main() {
    int first;
    int second;
    int ans, expectAns;

    first = 3;
    second = 2;
    expectAns = 3;
    TEST_SMP2(Solution, uniquePaths, expectAns, first, second);

    first = 7;
    second = 3;
    expectAns = 28;
    TEST_SMP2(Solution, uniquePaths, expectAns, first, second);

    return 0;
}


