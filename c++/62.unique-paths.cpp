/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
         // C(m + n - 2, m-1) or C(m + n - 2, n - 1)
        int x = std::min(m, n) - 1;
        int up = 1, down = 1; 
        for(int i = m + n -2; i > m + n - 2 - x; i--)  {
            up *= i;
        }
        for(int j = x; j > 0; i--)  {
            down *= j;
        }
        return up / down;
        
    }
};

