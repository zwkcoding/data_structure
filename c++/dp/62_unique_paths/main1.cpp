/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include "../../include/base.h"

/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
        // dp[0][j] = dp[i][0] = 1
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)  {
            for(int j = 1; j < n; j++)  {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m-1][n-1];
    }

/*
    /// Time Complexity: O(m * n)
    /// Space Complexity: O(2*n)
        int uniquePaths(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] = pre[j] + cur[j - 1];
            }
            swap(pre, cur);
        }
        return pre[n - 1];
    }

    /// Time Complexity: O(m * n)
    /// Space Complexity: O(n)
        int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }

*/

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


