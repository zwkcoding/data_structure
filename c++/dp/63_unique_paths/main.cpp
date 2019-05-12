/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [62] Unique Paths
 */

#include "../../include/base.h"

/// Time Complexity:  O(mn)
/// Space Complexity: O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        vector<int> cur(obs[0].size(), 0);
        //seed
        cur[0]=1;
        for(int i=0; i<obs.size(); i++) {
            bool allZero = true;
            for(int j=0; j<obs[0].size(); j++) {
                if(obs[i][j]) 
                    cur[j] = 0;
                else if(j > 0)
                    cur[j] += cur[j-1];
                if(cur[j] != 0) allZero=false;      // 每次更新必须能够到达下一行, 否则不可达到
            }
            if(allZero) break;
        }
        return cur[obs[0].size()-1];
    }

};


int main() {
    vector<vector<int>> first;
    int expectAns;

    first = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    expectAns = 2;
    TEST_SMP1(Solution, uniquePathsWithObstacles, expectAns, first);

    first =  {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};
    expectAns = 0;
    TEST_SMP1(Solution, uniquePathsWithObstacles, expectAns, first);

    first = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 0, 0}};
    expectAns = 2;
    TEST_SMP1(Solution, uniquePathsWithObstacles, expectAns, first);

     first = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 0}};
    expectAns = 0;
    TEST_SMP1(Solution, uniquePathsWithObstacles, expectAns, first);

    return 0;
}


